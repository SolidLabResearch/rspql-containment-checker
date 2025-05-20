/*
    Copyright (C) 2025 Kush Bisen (UGent - imec)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

const { Parser: SparqlParser } = require('sparqljs');

/**
 * Class for parsing an RSPQL query.
 * @class RSPQLParser
 */
export class RSPQLParser {
    private sparqlParser = new SparqlParser();

    /**
     * Parses an RSPQL query and extracts relevant informati;on.
     * @param {string} query - The RSPQL query to parse.
     * @returns {ParsedQuery} - The parsed query object containing extracted information.
     */
    parse(query: string): ParsedQuery {
        const parsed = new ParsedQuery();
        const split = query.split(/\r?\n/);
        const sparqlLines = new Array<string>();
        const originalSparqlLines = new Array<string>(); // For sparqljs parsing with aggregations
        const prefixMapper = new Map<string, string>();

        split.forEach((line) => {
            const trimmed_line = line.trim();

            if (trimmed_line.startsWith("REGISTER")) {
                const regexp = /REGISTER +([^ ]+) +<([^>]+)> AS/g;
                const matches = trimmed_line.matchAll(regexp);
                for (const match of matches) {
                    if (match[1] === "RStream" || match[1] === "DStream" || match[1] === "IStream") {
                        parsed.set_r2s({ operator: match[1], name: match[2] });
                    }
                }
                // Don’t add REGISTER to sparqlLines (pure SPARQL doesn’t need it)
                originalSparqlLines.push(trimmed_line);
                originalSparqlLines.push('PREFIX rsp: <http://rsp.org/>\n')
            } else if (trimmed_line.startsWith("FROM NAMED WINDOW")) {
                const regexp = /FROM +NAMED +WINDOW +([^ ]+) +ON +STREAM +([^ ]+) +\[RANGE +([^ ]+) +STEP +([^ ]+)\]/g;
                const matches = trimmed_line.matchAll(regexp);
                for (const match of matches) {
                    const windowName = this.unwrap(match[1], prefixMapper);
                    parsed.add_s2r({
                        window_name: windowName,
                        stream_name: this.unwrap(match[2], prefixMapper),
                        width: Number(match[3]),
                        slide: Number(match[4]),
                    });
                }
                originalSparqlLines.push(trimmed_line);
            } else {
                let sparqlLine = trimmed_line;
                if (sparqlLine.startsWith("WINDOW")) {
                    const windowMatch = sparqlLine.match(/WINDOW\s+([^ ]+)\s*\{/);
                    if (windowMatch) {
                        const windowNameRaw = windowMatch[1];         // e.g., ":w1"
                        const windowNameFull = this.unwrap(windowNameRaw, prefixMapper); // e.g., "http://example.org/w1"

                        const matchingS2R = parsed.s2r.find(w => w.window_name === windowNameFull);
                        if (matchingS2R) {
                            sparqlLine = sparqlLine.replace(/WINDOW\s+[^ ]+\s*\{/, `GRAPH ${this.iriToPrefixedName(matchingS2R.stream_name, prefixMapper)} {`);
                        } else {
                            console.warn(`No stream found for window: ${windowNameRaw}`);
                        }
                    }
                }
                if (sparqlLine.startsWith("PREFIX")) {
                    const regexp = /PREFIX +([^:]*): +<([^>]+)>/g;
                    const matches = trimmed_line.matchAll(regexp);
                    for (const match of matches) {
                        prefixMapper.set(match[1], match[2]);
                        parsed.prefixes.set(match[1], match[2]);
                    }

                    if (!prefixMapper.has('rsp')) {
                        prefixMapper.set('rsp', 'http://rsp.org/');
                        parsed.prefixes.set('rsp', 'http://rsp.org/');
                    }
                }
                if (sparqlLine.startsWith("SELECT")) {
                    // If line contains aggregation but not wrapped in parentheses, wrap it
                    const aggRegex = /SELECT\s+([A-Z]+\(.*\))\s+AS\s+\?([a-zA-Z0-9]+)/i;
                    const match = sparqlLine.match(aggRegex);

                    if (match) {
                        // match[1] = e.g. AVG(?v), match[2] = variable name
                        // Wrap entire aggregation as required by sparqljs parser:                        
                        sparqlLines.push(`SELECT (${match[1]} AS ?${match[2]})`);
                    } else {
                        sparqlLines.push(sparqlLine);
                    }
                    originalSparqlLines.push(trimmed_line);
                }

                else if (sparqlLine) {
                    sparqlLines.push(sparqlLine);
                    originalSparqlLines.push(sparqlLine);
                }
            }
        });

        // Ensure parsed.sparql is pure SPARQL
        parsed.sparql = sparqlLines.join("\n");



        for (let sparqlLine of originalSparqlLines) {
            if (sparqlLine.includes("GRAPH <")) {
                sparqlLine = sparqlLine.replace(/GRAPH +<([^>]+)>/g, (_, iri) => {
                    return `GRAPH ${this.iriToPrefixedName(iri, prefixMapper)}`;
                });
            }

        }


        const prefixes = Array.from(parsed.prefixes.entries())
            .map(([prefix, iri]) => `PREFIX ${prefix}: <${iri}>`)
            .join("\n");



        const finalQuery = `${prefixes}\n\n\n${parsed.sparql}`;
        parsed.set_sparql(finalQuery);
        // Parse the original SPARQL portion with aggregations for metadata
        const sparqlOnlyLines = sparqlLines.filter(
            line => !line.includes("FROM NAMED WINDOW") && !line.includes("REGISTER")
        );


        const sparqlOnlyQuery = sparqlOnlyLines.join("\n");
        try {
            console.log(sparqlOnlyQuery);
            const parsedSparql = this.sparqlParser.parse(sparqlOnlyQuery);
            this.extractAggregations(parsedSparql, parsed);
        } catch (error) {
            console.warn("Failed to parse SPARQL portion:", error);
        }

        return parsed;
    }

    /**
     * Extracts aggregation functions and variables from the parsed SPARQL query.
     * @param {any} parsedSparql - The parsed SPARQL query object.
     * @param {ParsedQuery} parsed - The ParsedQuery object to populate with extracted information.
     */
    private extractAggregations(parsedSparql: any, parsed: ParsedQuery) {
        if (parsedSparql.queryType === 'SELECT' && parsedSparql.variables) {
            parsedSparql.variables.forEach((variable: any) => {
                if (variable.expression && variable.expression.type === 'aggregate') {
                    parsed.aggregation_function = variable.expression.aggregation.toUpperCase();
                    parsed.aggregation_thing_in_context.push(variable.expression.expression.value);
                    parsed.projection_variables.push(variable.variable.value);
                } else if (variable.termType === 'Variable') {
                    parsed.projection_variables.push(variable.value);
                }
            });
        }
    }

    /**
     * Unwraps a prefixed IRI using the provided mapper.
     * @param {string} prefixedIri - The prefixed IRI to unwrap.
     * @param {Map<string, string>} mapper - The prefix mapper.
     * @returns {string} - The unwrapped IRI or an empty string if the prefix is not found.
     */
    unwrap(prefixedIri: string, mapper: Map<string, string>): string {
        if (prefixedIri.trim().startsWith("<")) {
            return prefixedIri.trim().slice(1, -1);
        }
        const split = prefixedIri.trim().split(":");
        const iri = split[0];
        if (mapper.has(iri)) {
            return mapper.get(iri) + split[1];
        } else {
            return "";
        }
    }

    iriToPrefixedName(iri: string, prefixMapper: Map<string, string>): string {
        for (const [prefix, ns] of prefixMapper.entries()) {
            if (iri.startsWith(ns)) {
                return `${prefix}:${iri.slice(ns.length)}`;
            }
        }
        // Return as-is if no prefix matched
        return `<${iri}>`;
    }

}

/**
 * The parsed query object.
 * @class ParsedQuery
 */
export class ParsedQuery {
    public prefixes: Map<string, string>;
    public aggregation_thing_in_context: Array<string>;
    public projection_variables: Array<string>;
    public aggregation_function: string;
    public sparql: string;
    public r2s: R2S;
    public s2r: Array<WindowDefinition>;


    /**
     * Creates an instance of ParsedQuery.
     * @memberof ParsedQuery
     */
    constructor() {
        this.sparql = "SELECT * WHERE{?s ?p ?o}";
        this.r2s = { operator: "RStream", name: "undefined" };
        this.s2r = new Array<WindowDefinition>();
        this.prefixes = new Map<string, string>();
        this.aggregation_thing_in_context = new Array<string>();
        this.projection_variables = new Array<string>();
        this.aggregation_function = "";
    }

    /**
     * Sets the SPARQL query string.
     * @param {string} sparql - The SPARQL query string to set.
     * @returns {void}
     * @memberof ParsedQuery
     */
    set_sparql(sparql: string) {
        this.sparql = sparql;
    }
    /**
     * Sets the R2S object.
     * @param {R2S} r2s - The R2S object to set.
     * @returns {void}
     * @memberof ParsedQuery
     */
    set_r2s(r2s: R2S) {
        this.r2s = r2s;
    }

    /**
     * Adds a prefix to the prefixes map.
     * @param {WindowDefinition} s2r - The S2R object to add.
     * @memberof ParsedQuery
     */
    add_s2r(s2r: WindowDefinition) {
        this.s2r.push(s2r);
    }
}

/**
 * Represents a window definition in the RSPQL query.
 * @class WindowDefinition
 */
export type WindowDefinition = {
    window_name: string;
    stream_name: string;
    width: number;
    slide: number;
};

/**
 * Represents the R2S object in the RSPQL query.
 * @class R2S
 */
export type R2S = {
    operator: "RStream" | "IStream" | "DStream";
    name: string;
};