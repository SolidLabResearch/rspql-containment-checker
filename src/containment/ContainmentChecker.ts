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

import { RSPQLParser } from "../parser/RSPQLParser";
import { ensurePromiseProperlyResolves } from "../util/Util";
import { SPeCSWrapper } from "./SPeCSWrapper";

/**
 * The ContainmentChecker class is responsible for checking the containment of two RSPQL queries.
 * It uses the RSPQLParser to parse the queries and the SPeCSWrapper to run the SPeCS tool for containment checking.
 * The class provides a method checkContainment that takes two RSPQL queries as input and returns a boolean indicating whether the first query is contained in the second.
 * @class ContainmentChecker
 */
export class ContainmentChecker {
    public parser: RSPQLParser;
    private specsWrapper: SPeCSWrapper;
    /**
     * Creates an instance of ContainmentChecker.
     * @memberof ContainmentChecker
     */
    constructor() {
        this.parser = new RSPQLParser();
        this.specsWrapper = new SPeCSWrapper();
    }

    /**
     * Checks the containment of two RSPQL queries.
     * It parses the queries using the RSPQLParser and then runs the SPeCS tool to check for containment.
     * If the queries are not valid or if the SPeCS tool fails, an error is thrown.
     * @param {string} query1 - The first RSPQL query to check.
     * @param {string} query2 - The second RSPQL query to check.
     * @throws {Error} - Throws an error if the queries are not valid or if the SPeCS tool fails.
     * @throws {Error} - Throws an error if the containment result is null.
     * @throws {Error} - Throws an error if the queries do not have the same stream name or aggregation function.
     * @throws {Error} - Throws an error if the queries cannot be parsed.
     * @throws {Error} - Throws an error if the SPeCS tool execution fails.
     * @throws {Error} - Throws an error if the parsed queries do not contain valid SPARQL.
     * @returns {Promise<boolean>} - Returns a promise that resolves to true if the first query is contained in the second, false otherwise.
     * @memberof ContainmentChecker
     */
    public async checkContainment(query1: string, query2: string): Promise<boolean> {
        const parsedQuery1 = this.parser.parse(query1);
        const parsedQuery2 = this.parser.parse(query2);
        if (parsedQuery1.r2s.operator === parsedQuery2.r2s.operator) {
            if (parsedQuery1.aggregation_function === parsedQuery2.aggregation_function) {

                if (!parsedQuery1 || !parsedQuery2) {
                    throw new Error("Failed to parse queries");
                }

                if (!parsedQuery1.sparql || !parsedQuery2.sparql) {
                    throw new Error("Parsed queries do not contain valid SPARQL");
                }

                const sparqlQuery1 = parsedQuery1.sparql;
                const sparqlQuery2 = parsedQuery2.sparql;

                const specsOptions = {
                    subquery: sparqlQuery1,
                    superquery: sparqlQuery2,
                };

                const specsResult = await this.specsWrapper.runSPeCS(specsOptions);
                ensurePromiseProperlyResolves();

                if (specsResult.exitCode !== 0) {
                    throw new Error(`SPeCS execution failed with exit code ${specsResult.exitCode}: ${specsResult.stderr}`);
                }
                if (specsResult.containment === null) {
                    throw new Error(`SPeCS execution returned null containment result: ${specsResult.stdout}`);
                }

                return specsResult.containment;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}