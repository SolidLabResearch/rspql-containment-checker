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