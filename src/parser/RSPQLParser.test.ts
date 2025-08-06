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
import { parse_sparql_query } from "rspql-query-isomorphism";
import {RSPQLParser} from "./RSPQLParser";


const simple_query = `PREFIX : <https://rsp.js/>
    REGISTER RStream <output> AS
    SELECT AVG(?v) AS ?avgTemp
    FROM NAMED WINDOW :w1 ON STREAM :stream1 [RANGE 10 STEP 2]
    WHERE{
        WINDOW :w1 { ?sensor :value ?v ; :measurement: ?m }
    }`;
const advanced_query = `PREFIX : <https://rsp.js/>
    REGISTER RStream <output> AS
    SELECT (AVG(?v) AS ?avgTemp)
    FROM NAMED WINDOW :w1 ON STREAM :stream1 [RANGE 10 STEP 2]
    FROM NAMED WINDOW :w2 ON STREAM :stream2 [RANGE 10 STEP 2]

    WHERE{
        ?sensor a :TempSensor.
        WINDOW :w1 { ?sensor :value ?v ; :measurement: ?m }
        WINDOW :w2 { ?sensor :value ?v ; :measurement: ?m }
    }`;

test('test_r2s', async () => {
    const parser = new RSPQLParser();
    const parsed_query = parser.parse(advanced_query);
    console.log(parsed_query.sparql);
    const expected_r2s = {operator: "RStream", name: "output"};
    console.log(parsed_query.r2s.operator);
    
    expect(parsed_query.r2s).toStrictEqual(expected_r2s);

});

test('test_single_window', async () => {
    const parser = new RSPQLParser();
    const parsed_query = parser.parse(simple_query);

    const expected_windows = {window_name: "https://rsp.js/w1",
        stream_name: "https://rsp.js/stream1",
        width: 10,
        slide: 2};
    expect(parsed_query.s2r[0]).toStrictEqual(expected_windows);
});

test('test_multiple_window', async () => {
    const parser = new RSPQLParser();
    const parsed_query = parser.parse(advanced_query);
    console.log(parsed_query);
    

    const expected_windows = [{window_name: "https://rsp.js/w1",
        stream_name: "https://rsp.js/stream1",
        width: 10,
        slide: 2},
        {window_name: "https://rsp.js/w2",
            stream_name: "https://rsp.js/stream2",
            width: 10,
            slide: 2}
    ];
    expect(parsed_query.s2r).toStrictEqual(expected_windows);
});
test('test_simple_sparql_extract', async () => {
    const parser = new RSPQLParser();
    const parsed_query = parser.parse(simple_query);

    const expected_sparql =
        `PREFIX : <https://rsp.js/>
SELECT AVG(?v) as ?avgTemp
WHERE{
GRAPH :w1 { ?sensor :value ?v ; :measurement: ?m }
}`;
    expect(parsed_query.sparql).toStrictEqual(expected_sparql);
});

test('test_sparql_extract_multiple_windows', async () => {
    const parser = new RSPQLParser();
    const parsed_query = parser.parse(advanced_query);

    const expected_sparql =
        `PREFIX : <https://rsp.js/>
SELECT AVG(?v) as ?avgTemp

WHERE{
?sensor a :TempSensor.
GRAPH :w1 { ?sensor :value ?v ; :measurement: ?m }
GRAPH :w2 { ?sensor :value ?v ; :measurement: ?m }
}`;
    expect(parsed_query.sparql).toStrictEqual(expected_sparql);
});

test('parse RSPQL queries with multiple windows and different basic graph patterns', async () => {
        const superQuery = `
PREFIX mqtt_broker: <mqtt://localhost:1883/>
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js> 
REGISTER RStream <output> AS
SELECT (AVG(?o) AS ?avgX) (AVG(?o2) AS ?avgY) (AVG(?o3) AS ?avgZ)
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:accX [RANGE 120000 STEP 30000]
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:accY [RANGE 120000 STEP 30000]
FROM NAMED WINDOW :w3 ON STREAM mqtt_broker:accZ [RANGE 120000 STEP 30000]
WHERE {
   { WINDOW :w1 {
        ?s saref:hasValue ?o .
        ?s saref:relatesToProperty dahccsensors:wearable.acceleration.x .
}}
    UNION
    { WINDOW :w2 {
        ?s2 saref:hasValue ?o2 .
        ?s2 saref:relatesToProperty dahccsensors:wearable.acceleration.y .
    }}
    UNION
    { WINDOW :w3 {
        ?s3 saref:hasValue ?o3 .
        ?s3 saref:relatesToProperty dahccsensors:wearable.acceleration.z .
    }}
}
    `;

    const parser = new RSPQLParser();
    const parsed_query = parser.parse(superQuery);
    console.log(parsed_query.sparql);
});

test("parse UNION queries", async () => {
        const registeredQuery = `
PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js> 
REGISTER RStream <output> AS
SELECT (AVG(?o) AS ?avgWearableX) (AVG(?o2) AS ?avgSmartphoneX) 
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:wearableX [RANGE 120000 STEP 60000]
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:smartphoneX [RANGE 120000 STEP 60000]
WHERE {
   { 
    WINDOW :w1 {
        ?s1 saref:hasValue ?o .
        ?s1 saref:relatesToProperty dahccsensors:wearableX .
}}
    UNION
    { 
    WINDOW :w2 {
        ?s2 saref:hasValue ?o2 .
        ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
    }}
}
    `;
   const parser = new RSPQLParser();
   const parsed_query = parser.parse(registeredQuery);
   console.log(parsed_query.sparql);

});

test("parse queries with GRAPH", async () => {
        const query1 = `
            PREFIX mqtt_broker: <mqtt://localhost:1883/>
    PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js> 
REGISTER RStream <output> AS
SELECT (AVG(?o) AS ?avgWearableX)
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:wearableX [RANGE 60000 STEP 60000]
WHERE {
    WINDOW :w1 {
        ?s1 saref:hasValue ?o .
        ?s1 saref:relatesToProperty dahccsensors:wearableX .
    }
}
    `;

    const parser = new RSPQLParser();
    const parsed_query = parser.parse(query1);
    console.log(parsed_query);
});

test("parsing subqueries with WINDOW", async () => {
   const query = `PREFIX mqtt_broker: <mqtt://localhost:1883/>
PREFIX saref: <https://saref.etsi.org/core/>
PREFIX dahccsensors: <https://dahcc.idlab.ugent.be/Homelab/SensorsAndActuators/>
PREFIX : <https://rsp.js>
REGISTER RStream <output> AS
SELECT ?avgCombinedX ?avgCombinedX2
FROM NAMED WINDOW :w1 ON STREAM mqtt_broker:wearableX [RANGE 10 STEP 2]
FROM NAMED WINDOW :w2 ON STREAM mqtt_broker:smartphoneX [RANGE 10 STEP 2]
WHERE {
    {
        SELECT (AVG(?o) AS ?avgCombinedX)
        WHERE {
            WINDOW :w1 {
                ?s saref:hasValue ?o .
                ?s saref:relatesToProperty dahccsensors:wearableX .
            }
        }
    }
    {
        SELECT (AVG(?o2) AS ?avgCombinedX2)
        WHERE {
            WINDOW :w2 {
                ?s2 saref:hasValue ?o2 .
                ?s2 saref:relatesToProperty dahccsensors:smartphoneX .
            }
        }
    }
}`;

    const parser = new RSPQLParser();
    const parsed_query = parser.parse(query);
    console.log(parsed_query.sparql);
})