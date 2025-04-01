import { createServer, ServerResponse, IncomingMessage, Server } from "http";
import { GETHandler } from "./handlers/GETHandler";
import { POSTHandler } from "./handlers/POSTHandler";

export class HTTPServer {
    private readonly http_server: Server;
    public logger: any;
    constructor(http_port: number, logger: any) {
        this.http_server = createServer(this.request_handler.bind(this)).listen(http_port);
        this.logger = logger;
        this.logger.info(`HTTP server started on port ${http_port}`);
    }

    private async request_handler(request: IncomingMessage, response: ServerResponse) {
        response.setHeader("Access-Control-Allow-Origin", "*");
        response.setHeader("Access-Control-Allow-Headers", "*");
        response.setHeader("Access-Control-Allow-Methods", "*");

        let body: string = "";

        switch (request.method) {
            case "GET":
                this.logger.info(`GET request received: ${request.url}`);
                GETHandler.handle(request, response);
                // No response.end() here; GETHandler should handle it
                break;
            case "POST":
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
            default:
                response.statusCode = 405;
                response.setHeader("Content-Type", "application/json");
                const errorResponse = JSON.stringify({ error: "Method Not Allowed" });
                response.setHeader("Content-Length", Buffer.byteLength(errorResponse));
                response.write(errorResponse);
                response.end();
        }
    }
}