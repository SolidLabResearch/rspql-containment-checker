# RSPQL Containment Checker

The RSPQL Containment Checker is a tool that extends the [SPeCS](https://github.com/mirkospasic/SpeCS) SPARQL Containment solver to check containment between two RSP-QL queries. The RSP-QL queries are translated to SPARQL queries, along with their streaming semantics, and then the containment is checked using the SPeCS tool for the SPARQL queries. The streaming semantics are utilized to determine if the RSP-QL queries are on the same data source and if they are compatible for containment checking.
Once the compatibility is established, the containment checking is performed using the SPeCS tool. 

The RSP-QL containment checker is presented as a HTTP service that can be accessed via a REST API. The server accepts RSP-QL queries and returns the containment result. The RSP-QL containment checker is implemented with Typescript and Node.js. 

# Prerequisites
To run the RSPQL Containment Checker, you need to have the following software installed on your machine:
- [Node.js](https://nodejs.org/en/) (v20.0.0 or higher)
- [npm](https://www.npmjs.com/) (v9.0.0 or higher)
- [Z3 Solver](https://github.com/Z3Prover/z3) needs to be installed as well to execute the tool.

# Installation
To install the RSPQL Containment Checker, follow these steps:

1. Install the relevant dependencies:
   ```bash
   npm install
   ```
2. Build the project:
   ```bash
   npm run build
   ```
3. Start the containment checker tool with
   ```bash
   npm run start containment-checker
   ```
This will start the RSPQL Containment Checker server on `http://localhost:8085`. You can change the port in the `src/index.ts` file.

The RSPQL containment checker is implemented as a REST API. You can use any HTTP client to send requests to the server. The server accepts RSP-QL queries and returns the containment result in JSON format.

# API Endpoints

The RSPQL Containment Checker provides the following API endpoints:
- `POST /containment`: This endpoint checks the containment of two RSP-QL queries. The request body should contain the following JSON object:
```json
{
  "subquery": "<RSP-QL query 1>",
  "superquery": "<RSP-QL query 2>"
}
```
The response will contain the containment result in the following format:
```json
{
  "containment": "<boolean value of true | false>",
}
```

# Example Usage

When the containment checker is up and running,

For the two RSP-QL queries:
```sparql
PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (COUNT(?x) AS ?count)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
    WINDOW ex:w1 { ?x a ex:Person. }
}
```
and

```sparql
PREFIX ex: <http://example.org/>
REGISTER RStream <output> AS
SELECT (COUNT(?x) AS ?count)
FROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]
WHERE {
  WINDOW ex:w1 { 
    ?x a ex:Person.
    ?x ex:hasAge ex:One.
  }
}
```
You can check the containment between the queries by doing a POST request to the `/containment` endpoint with the following example of JSON:
```json
{
  "subquery": "PREFIX ex: <http://example.org/>\nREGISTER RStream <output> AS\nSELECT (COUNT(?x) AS ?count)\nFROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]\nWHERE {\n    WINDOW ex:w1 { ?x a ex:Person. }\n}",
  "superquery": "PREFIX ex: <http://example.org/>\nREGISTER RStream <output> AS\nSELECT (COUNT(?x) AS ?count)\nFROM NAMED WINDOW ex:w1 ON STREAM ex:stream1 [RANGE 10 STEP 5]\nWHERE {\n  WINDOW ex:w1 { \n    ?x a ex:Person.\n    ?x ex:hasAge ex:One.\n  }\n}"
}
```

The server will respond with the containment result:
```json
{
  "containment": true
}
```
This indicates that the first query is contained in the second query.


# License
The code is licensed under the GPL-3.0 License. See the [LICENSE](LICENSE) file for details.

# Acknowledgements
We would like to thank the authors of the [SPeCS](https://github.com/mirkospasic/SpeCS) tool for their work on SPARQL containment checking. The RSPQL Containment Checker builds upon their work and extends it to support RSP-QL queries. 

# Contact
For any questions regarding the repository, please contact [Kush](mailto:kushbisen@proton.me) or open an issue on the repository.