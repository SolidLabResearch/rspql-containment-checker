import { ContainmentChecker } from "./containment/ContainmentChecker";
import { RSPQLParser } from "./parser/RSPQLParser";

async function main() {
    const multiWindowQuery = `
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX AccelerometerX: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.x>
PREFIX AccelerometerY: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.y>
PREFIX AccelerometerZ: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.z>
PREFIX ex: <https://rsp.js/>

REGISTER RStream <output> AS
SELECT (AVG(?o) AS ?avgX) (AVG(?o2) AS ?avgY) (AVG(?o3) AS ?avgZ)
FROM NAMED WINDOW ex:w1 ON STREAM <acc-x> [RANGE 60000 STEP 60000]
FROM NAMED WINDOW ex:w2 ON STREAM <acc-y> [RANGE 60000 STEP 60000]
FROM NAMED WINDOW ex:w3 ON STREAM <acc-z> [RANGE 60000 STEP 60000]
WHERE {
  {
    WINDOW ex:w1 {
      ?s saref:hasValue ?o .
      ?s saref:relatesToProperty AccelerometerX: .
    }
  }
  UNION
  {
    WINDOW ex:w2 {
      ?s saref:hasValue ?o2 .
      ?s saref:relatesToProperty AccelerometerY: .
    }
  }
  UNION
  {
    WINDOW ex:w3 {
      ?s saref:hasValue ?o3 .
      ?s saref:relatesToProperty AccelerometerZ: .
    }
  }
}
    `;

    const parser = new RSPQLParser();
    const parsedQuery = parser.parse(multiWindowQuery);
    const sparql = `
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX AccelerometerX: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.x>
PREFIX AccelerometerY: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.y>
PREFIX AccelerometerZ: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.z>
PREFIX ex: <https://rsp.js/>
SELECT ?o ?o2 ?o3
WHERE {
{ GRAPH ex:w1 {
?s saref:hasValue ?o .
?s saref:relatesToProperty AccelerometerX: . }}
UNION
{ GRAPH ex:w2 {
?s saref:hasValue ?o2 .
?s saref:relatesToProperty AccelerometerY: . }}
UNION
{ GRAPH ex:w3 {
?s saref:hasValue ?o3 .
?s saref:relatesToProperty AccelerometerZ: . }}
}
    `;

    const test_query = `
        PREFIX saref: <https://saref.etsi.org/core/>
PREFIX AccelerometerX: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.x>
PREFIX AccelerometerY: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.y>
PREFIX AccelerometerZ: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/wearable.acceleration.z>
PREFIX ex: <https://rsp.js/>
SELECT ?o
WHERE {
{ GRAPH ex:w1 {
?s saref:hasValue ?o .
?s saref:relatesToProperty AccelerometerX: . }}}
    `;

    try {
        console.log(`Checking containment for the following queries:`);
        console.log(`Query 1: ${sparql}`);
        console.log(`Query 2: ${test_query}`);
        const checker = new ContainmentChecker();
        const result = await checker.checkContainment(sparql, test_query);
        console.log(`Containment result: ${result}`);

    } catch (error) {
        console.error("An error occurred:", error);

    }
}

main().catch(console.error);