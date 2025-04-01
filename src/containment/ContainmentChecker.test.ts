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