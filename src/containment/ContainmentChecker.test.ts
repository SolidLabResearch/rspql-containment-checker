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
    SELECT (AVG(?x) AS ?avg)
    FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
    WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
    }`;
    const rspqlSuperQuery = `PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (AVG(?x) AS ?avg)
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
  })
});