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
import { ContainmentChecker } from "./ContainmentChecker";

describe("Testing the containment checker class", () => {
  it("should check containment for two rspql queries", async () => {
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT ?x
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT ?x
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 { 
    ?x a ex:Person.
    ?x ex:hasAge ex:One.
  }
}
`;
    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(true);

  });
  it("check containment for queries with aggregation functions", async () => {
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (COUNT(?x) AS ?count)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 { 
    ?x a ex:Person.
    ?x ex:hasAge ex:One.
  }
}
`;
    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(true);
  });

  it("check containment for queries with different aggregation functions", async () => {
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;

    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (MIN(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
      WINDOW ex:w1 { 
        ?x a ex:Person.
        ?x ex:hasAge ex:One.
      }
    }
    `;

    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(false);
  });


  it("check containment with different window semantics", async () => {
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 100 STEP 50]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (COUNT(?x) AS ?count)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 { 
    ?x a ex:Person.
    ?x ex:hasAge ex:One.
  }
}
`;
    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(true);
  });

  it("check containment for queries wqith different streams", async () => {
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    FROM NAMED WINDOW ex:w2 ON STREAM ex:stream2 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    WINDOW ex:w2 { ?x ex:hasAge ex:One. }
    }`;

    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(true);
  });

  it("should fail containment with different streams", async () => {
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
      REGISTER RStream <output> AS
      SELECT ?x
      FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
      WHERE {
        WINDOW ex:w1 { ?x a ex:Person. }
      }`;
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
      REGISTER RStream <output> AS
      SELECT ?x
      FROM NAMED WINDOW ex:w1 ON STREAM ex:stream2 [RANGE 10 STEP 5]
      WHERE {
        WINDOW ex:w1 { 
          ?x a ex:Person.
          ?x ex:hasAge ex:One.
        }
      }`;
    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(false);
  });

  it("checking with saref ontology", async () => {
    const rspqlSubQuery = `
PREFIX ex: <http://example.org/>
PREFIX saref: <http://www.w3.org/ns/saref#>
PREFIX dahccsensors: <http://example.org/dahccsensors#>
PREFIX : <http://example.org/stream#>
REGISTER RStream <output> AS
SELECT ?o
FROM NAMED WINDOW :w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
WHERE {
    WINDOW :w1 {
        ?s saref:hasValue ?o .
        ?s saref:relatesToProperty dahccsensors:x .
    }
}
    `;
    const rspqlSuperQuery = `
    PREFIX ex: <http://example.org/>
    PREFIX saref: <http://www.w3.org/ns/saref#>
PREFIX dahccsensors: <http://example.org/dahccsensors#>
PREFIX : <http://example.org/stream#>
REGISTER RStream <output> AS
SELECT ?o
FROM NAMED WINDOW :w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
WHERE {
      WINDOW :w1 {
          ?s saref:hasValue ?o .
      }       
  } 
    `;

    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(true);
  });

  test("check containment for average age of the people", async () => {
    const subQuery = `
    PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (AVG(?age) AS ?averageAge)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 { 
    ?person a ex:Employee.
    ?person ex:hasAge ?age.
  }
}`;

    const superQuery = `
PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (AVG(?age) AS ?avgSubsetAge)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 {
    ?person ex:hasAge ?age.
  }
}`;

    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(subQuery, superQuery);
    expect(result).toBe(true);
  });

  test("check containment for different R2S operators", async () => {
    const subQuery = `
    PREFIX ex: <http://example.org/>
REGISTER IStream <output> AS
SELECT (AVG(?age) AS ?averageAge)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 { 
    ?person a ex:Employee.
    ?person ex:hasAge ?age.
  }
}`;

    const superQuery = `
PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (AVG(?age) AS ?avgSubsetAge)
FROM NAMED WINDOW ex:w2 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w2 {
    ?person ex:hasAge ?age.
  }
}`;


    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(subQuery, superQuery);
    expect(result).toBe(true);
  })

});

test("checking containment with different subqueries inside of a query", async () => {
  const query = `
  PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js>
REGISTER RStream <output> AS
SELECT ?avgCombinedX ?avgCombinedX2
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:wearableX [RANGE 10 STEP 2]
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:smartphoneX [RANGE 10 STEP 2]
WHERE {
    {
        SELECT (?o AS ?avgCombinedX)
        WHERE {
            WINDOW :w1 {
                ?s saref:hasValue ?o .
                ?s saref:relatesToProperty dahccsensors:wearableX .
            }
        }
    }
    {
        SELECT (?o2 AS ?avgCombinedX2)
        WHERE {
            WINDOW :w2 {
                ?s2 saref:hasValue ?o2 .
                ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
            }
        }
    }
}
  `;

  const containmentChecker = new ContainmentChecker();
  const result = await containmentChecker.checkContainment(query, query);
  expect(result).toBe(true);
});

test("check containment for a subquery containing query and a normal query", async () => {
  const query2 = `
                PREFIX mqtt_broker: <mqtt://localhost:1883/>
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js> 
REGISTER RStream <output> AS
SELECT ((?o2) AS ?avgSmartphoneX)
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:smartphoneX [RANGE 60000 STEP 60000]
WHERE {
    WINDOW :w2 {
        ?s2 saref:hasValue ?o2 .
        ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
    }
}
    `;

  const query = `
  PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js>
REGISTER RStream <output> AS
SELECT ?avgCombinedX ?avgCombinedX2
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:wearableX [RANGE 60000 STEP 60000]
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:smartphoneX [RANGE 60000 STEP 60000]
WHERE {
    {
        SELECT (?o AS ?avgCombinedX)
        WHERE {
            WINDOW :w1 {
                ?s saref:hasValue ?o .
                ?s saref:relatesToProperty dahccsensors:wearableX .
            }
        }
    }
    {
        SELECT (?o2 AS ?avgCombinedX2)
        WHERE {
            WINDOW :w2 {
                ?s2 saref:hasValue ?o2 .
                ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
            }
        }
    }
}
  `;

  const biggerQuery = `
PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js>
REGISTER RStream <output> AS
SELECT *
FROM NAMED WINDOW <mqtt://localhost:1883/wearableX> ON STREAM mqtt_broker:wearableX [RANGE 120000 STEP 60000]
FROM NAMED WINDOW <mqtt://localhost:1883/smartphoneX> ON STREAM mqtt_broker:smartphoneX [RANGE 120000 STEP 60000]
WHERE {{
WINDOW <mqtt://localhost:1883/wearableX> {
    {
        SELECT (AVG(?o) AS ?avgCombinedX)
        WHERE {
            WINDOW <mqtt://localhost:1883/wearableX> {
                ?s saref:hasValue ?o .
                ?s saref:relatesToProperty dahccsensors:wearableX .
            }
        }
}}}
    UNION{
WINDOW <mqtt://localhost:1883/smartphoneX> {
    {
        SELECT (AVG(?o2) AS ?avgCombinedX2)
        WHERE {
            WINDOW <mqtt://localhost:1883/smartphoneX> {
                ?s2 saref:hasValue ?o2 .
                ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
            }
        }
}
}}
}
`;

  const works_query = `
PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js>

REGISTER RStream <output> AS
SELECT (AVG(?v1) AS ?avgWearableX) (AVG(?v2) AS ?avgSmartphoneX)
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:wearableX [RANGE 60000 STEP 60000]
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:smartphoneX [RANGE 60000 STEP 60000]
WHERE {
  WINDOW :w1 {
    ?s1 saref:hasValue ?v1 .
    ?s1 saref:relatesToProperty dahccsensors:wearableX .
  }
  WINDOW :w2 {
    ?s2 saref:hasValue ?v2 .
    ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
  }
}
`;

const new_query = 
`
PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js>
REGISTER RStream <output> AS
SELECT ?avgCombinedX ?avgCombinedX2
FROM NAMED WINDOW <mqtt://localhost:1883/wearableX> ON STREAM mqtt_broker:wearableX [RANGE 120000 STEP 60000]
FROM NAMED WINDOW <mqtt://localhost:1883/smartphoneX> ON STREAM mqtt_broker:smartphoneX [RANGE 120000 STEP 60000]
WHERE {
  WINDOW <mqtt://localhost:1883/wearableX> {
    {
      SELECT (AVG(?o) AS ?avgCombinedX)
      WHERE {
        WINDOW <mqtt://localhost:1883/wearableX> {
          ?s saref:hasValue ?o .
          ?s saref:relatesToProperty dahccsensors:wearableX .
        }
      }
    }
  }
}
`


  let parser = new RSPQLParser().parse(works_query).sparql;
  console.log("Parsed query:", parser);

  const query2Parser = new RSPQLParser().parse(query2).sparql;
  console.log("Parsed query2:", query2Parser);

  const containmentChecker = new ContainmentChecker();
  const result = await containmentChecker.checkContainment(new_query, biggerQuery);
  // expect(result).toBe(true);
  console.log("Containment result:", result);



  // Uncomment the following line if you want to check the containment in the opposite direction
  // const result2 = await containmentChecker.checkContainment(query2, query);
  // expect(result2).toBe(true);
  // // expect(result).toBe(true);
  // const result2 = await containmentChecker.checkContainment(query, query2);
  // expect(result2).toBe(false);
});