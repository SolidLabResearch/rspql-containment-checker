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
    const expected_r2s = {operator: "RStream", name: "output"};
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
