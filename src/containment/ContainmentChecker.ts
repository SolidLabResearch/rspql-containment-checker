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
import { SPeCSWrapper } from "./SPeCSWrapper";

export class ContainmentChecker {
    public parser: RSPQLParser;
    private specsWrapper: SPeCSWrapper;
    constructor() {
        this.parser = new RSPQLParser();
        this.specsWrapper = new SPeCSWrapper();
    }

    public async checkContainment(query1: string, query2: string): Promise<boolean> {
        const parsedQuery1 = this.parser.parse(query1);
        const parsedQuery2 = this.parser.parse(query2);
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
                superquery: sparqlQuery1,
                subquery: sparqlQuery2,
            };

            console.log(`SPeCS options: ${JSON.stringify(specsOptions)}`);
            

            const specsResult = await this.specsWrapper.runSPeCS(specsOptions);

            if (specsResult.exitCode !== 0) {
                throw new Error(`SPeCS execution failed with exit code ${specsResult.exitCode}: ${specsResult.stderr}`);
            }
            if (specsResult.containment === null) {
                throw new Error(`SPeCS execution returned null containment result: ${specsResult.stdout}`);
            }

            return specsResult.containment;
        }
        else {
            throw new Error("The aggregation functions in the queries do not match. Containment check cannot be performed.");
        }
    }
}