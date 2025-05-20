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