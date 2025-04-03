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

import { ContainmentChecker } from "./ContainmentChecker";

describe("Testing the containment checker class", () => {
  it("should check containment for two rspql queries", async () => {
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
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
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
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 100 STEP 50]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
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
    const rspqlSubQuery = `PREFIX ex: <http://example.org/>
    REGISTER RStream <output> AS
    SELECT (COUNT(?x) AS ?count)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
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
REGISTER RStream <output> AS
SELECT ?o
FROM NAMED WINDOW :w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
WHERE {
    WINDOW :w1 {
        ?s saref:hasValue ?o .
        ?s saref:relatesToProperty dahccsensors:wearable.acceleration.x .
    }
}
    `;
    const rspqlSuperQuery = `
PREFIX ex: <http://example.org/> 
REGISTER RStream <output> AS
SELECT ?o ?o2 ?o3 
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
FROM NAMED WINDOW ex:w2 ON STREAM ex:stream2 [RANGE 60000 STEP 20000]
FROM NAMED WINDOW ex:w3 ON STREAM ex:stream3 [RANGE 60000 STEP 20000]
WHERE {
    WINDOW :w1 {
        ?s ex:hasValue ?o .
        ?s ex:relatesToProperty ex:wearable.acceleration.x .
    }
    WINDOW :w2 {
        ?s ex:hasValue ?o2 .
        ?s ex:relatesToProperty ex:wearable.acceleration.y .
    }   
    WINDOW :w3 {
        ?s ex:hasValue ?o3 .
        ?s ex:relatesToProperty ex:wearable.acceleration.z .    
    }
}
    `;

    const rspqlSuperQueryWithBound = `
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js/>
REGISTER RStream <output> AS
SELECT ?o ?o2 ?o3
FROM NAMED WINDOW :w1 ON STREAM :stream1 [RANGE 60000 STEP 20000]
FROM NAMED WINDOW :w2 ON STREAM :stream2 [RANGE 60000 STEP 20000]
FROM NAMED WINDOW :w3 ON STREAM :stream3 [RANGE 60000 STEP 20000]
WHERE {
    GRAPH :w1 {
        ?s saref:hasValue ?o .
        ?s saref:relatesToProperty dahccsensors:wearable.acceleration.x .
    }
    {
        SELECT ?o2
        WHERE {
            GRAPH :w2 {
                ?s2 saref:hasValue ?o2 .
                ?s2 saref:relatesToProperty dahccsensors:wearable.acceleration.y .
            }
        }
    } UNION {
        BIND("N/A" AS ?o2)
    }
    {
        SELECT ?o3
        WHERE {
            GRAPH :w3 {
                ?s3 saref:hasValue ?o3 .
                ?s3 saref:relatesToProperty dahccsensors:wearable.acceleration.z .
            }
        }
    } UNION {
        BIND("N/A" AS ?o3)
    }
}
    `;

    const subquery = `PREFIX ex: <http://example.org/> 

REGISTER RStream <output> AS
SELECT ?o ?o2 ?o3 
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
FROM NAMED WINDOW ex:w2 ON STREAM ex:stream2 [RANGE 60000 STEP 20000]
FROM NAMED WINDOW ex:w3 ON STREAM ex:stream3 [RANGE 60000 STEP 20000]
WHERE {
    WINDOW ex:w1 {
        {
            SELECT ?s ?o
            WHERE {
                ?s ex:hasValue ?o .
                ?s ex:relatesToProperty ex:wearable.acceleration.x .
            }
        }
    }
    WINDOW ex:w2 {
        {
            SELECT ?s ?o2
            WHERE {
                ?s ex:hasValue ?o2 .
                ?s ex:relatesToProperty ex:wearable.acceleration.y .
            }
        }
    }   
    WINDOW ex:w3 {
        {
            SELECT ?s ?o3
            WHERE {
                ?s ex:hasValue ?o3 .
                ?s ex:relatesToProperty ex:wearable.acceleration.z .    
            }
        }
    }
}
`

    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(subquery, rspqlSuperQuery);
    expect(result).toBe(true);
  });

  test("just a test", async () => {
    const rspqlSubQuery = `
PREFIX ex: <http://example.org/>
PREFIX : <https://rsp.js/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
REGISTER RStream <output> AS
SELECT ?o
FROM NAMED WINDOW :w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
WHERE {
    WINDOW :w1 {
        ?s saref:hasValue ?o .
        ?s saref:relatesToProperty dahccsensors:wearable.acceleration.x .
    }
}
    `;

    const rspqlSuperQuery = `
PREFIX ex: <http://example.org/>
PREFIX : <https://rsp.js/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
REGISTER RStream <output> AS
SELECT ?o
FROM NAMED WINDOW :w1 ON STREAM ex:stream1 [RANGE 60000 STEP 20000]
WHERE {
    WINDOW :w1 {
        ?s saref:hasValue ?o .
        ?s saref:relatesToProperty dahccsensors:wearable.acceleration.x .
    }
}
    `;

    const containmentChecker = new ContainmentChecker();
    const result = await containmentChecker.checkContainment(rspqlSubQuery, rspqlSuperQuery);
    expect(result).toBe(true);
  });

});