import { ContainmentChecker } from "./containment/ContainmentChecker";
import { RSPQLParser } from "./parser/RSPQLParser";

async function main() {
    const checker = new ContainmentChecker();
    const subQuery = `
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors : <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX ex: <https://rsp.js/>
SELECT ?o
WHERE {
{ GRAPH ex:w1 {
?s saref:hasValue ?o .
?s saref:relatesToProperty dahccsensors:x . }
}
}
    `;
    const superQuery = `
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors : <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX ex: <https://rsp.js/>
SELECT ?o ?o2 ?o3
WHERE {
{ GRAPH ex:w1 {
?s saref:hasValue ?o .
?s saref:relatesToProperty dahccsensors:x . }}
UNION
{ GRAPH ex:w2 {
?s saref:hasValue ?o2 .
?s saref:relatesToProperty dahccsensors:y . }}
UNION
{ GRAPH ex:w3 {
?s saref:hasValue ?o3 .
?s saref:relatesToProperty dahccsensors:z . }}
}
    `;

    try {
        console.log(`Checking containment for the following queries:`);
        console.log(`Query 1: ${subQuery}`);
        console.log(`Query 2: ${superQuery}`)
        const result = await checker.checkContainment(subQuery, superQuery);
        console.log(`Containment result: ${result}`);

    } catch (error) {
        console.error(`Error checking containment: ${error}`);
    }
}

main().catch(console.error);