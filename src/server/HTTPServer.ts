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

import { createServer, ServerResponse, IncomingMessage, Server } from "http";
import { GETHandler } from "./handlers/GETHandler";
import { POSTHandler } from "./handlers/POSTHandler";

/**
 * HTTPServer is a class that creates an HTTP server to handle incoming requests.
 * It listens on a specified port and routes requests to appropriate handlers based on the HTTP method (GET or POST).
 * The class also sets CORS headers to allow cross-origin requests.
 * @class HTTPServer
 */
export class HTTPServer {
    private readonly http_server: Server;
    public logger: any;
    /**
     * Creates an instance of HTTPServer.
     * @param {number} http_port - The port number on which the server will listen for incoming requests.
     * @param {any} logger - A logger instance for logging messages.
     * @memberof HTTPServer
     */
    constructor(http_port: number, logger: any) {
        this.http_server = createServer(this.request_handler.bind(this)).listen(http_port);
        this.logger = logger;
        this.logger.info(`HTTP server started on port ${http_port}`);
    }

    /**
     * Handles incoming HTTP requests.
     * It sets CORS headers and routes the request to the appropriate handler based on the HTTP method (GET or POST).
     * @param {IncomingMessage} request - The incoming HTTP request.
     * @param {ServerResponse} response - The HTTP response to be sent back.
     * @memberof HTTPServer
     */
    private async request_handler(request: IncomingMessage, response: ServerResponse) {
        response.setHeader("Access-Control-Allow-Origin", "*");
        response.setHeader("Access-Control-Allow-Headers", "*");
        response.setHeader("Access-Control-Allow-Methods", "*");

        let body: string = "";

        switch (request.method) {
            case "GET": {
                this.logger.info(`GET request received: ${request.url}`);
                GETHandler.handle(request, response);
                // No response.end() here; GETHandler should handle it
                break;
            }
            case "POST": {
                body = await new Promise<string>((resolve) => {
                    let data = "";
                    request.on("data", (chunk: Buffer) => {
                        data += chunk.toString();
                    });
                    request.on("end", () => resolve(data));
                });
                this.logger.info(`POST request received: ${request.url}`);
                await POSTHandler.handle(request, response, body);
                // No response.end() here; POSTHandler handles it
                break;
            }
            default: {
                response.statusCode = 405;
                response.setHeader("Content-Type", "application/json");
                const errorResponse = JSON.stringify({ error: "Method Not Allowed" });
                response.setHeader("Content-Length", Buffer.byteLength(errorResponse));
                response.write(errorResponse);
                response.end();
            }
        }
    }
}