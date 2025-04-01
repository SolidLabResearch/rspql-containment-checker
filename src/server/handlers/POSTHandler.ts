import { IncomingMessage, ServerResponse } from "http";
import { ContainmentChecker } from "../../containment/ContainmentChecker";

export class POSTHandler {
    public static async handle(request: IncomingMessage, response: ServerResponse, body: string) {
        response.setHeader("Content-Type", "application/json");

        let parsedBody: any;
        try {
            parsedBody = JSON.parse(body);
        } catch (error) {
            response.statusCode = 400;
            const errorResponse = JSON.stringify({ error: "Invalid JSON" });
            response.setHeader("Content-Length", Buffer.byteLength(errorResponse));
            response.write(errorResponse);
            response.end();
            return;
        }

        try {
            switch (request.url) {
                case "/containment":
                    await this.handleContainment(parsedBody, response);
                    break;
                default:
                    response.statusCode = 404;
                    const notFoundResponse = JSON.stringify({
                        error: "Not Found",
                        message: "The requested URL was not found on this server."
                    });
                    response.setHeader("Content-Length", Buffer.byteLength(notFoundResponse));
                    response.write(notFoundResponse);
                    response.end();
            }
        } catch (error) {
            if (!response.headersSent) {
                response.statusCode = 500;
                const errorResponse = JSON.stringify({
                    error: "Internal Server Error",
                    message: error instanceof Error ? error.message : "Unknown error"
                });
                response.setHeader("Content-Length", Buffer.byteLength(errorResponse));
                response.write(errorResponse);
                response.end();
            }
        }
    }

    private static async handleContainment(parsedBody: any, response: ServerResponse) {
        const subquery = parsedBody.subquery;
        const superquery = parsedBody.superquery;
        if (parsedBody.)

        const containmentChecker = new ContainmentChecker();
        // Log headers state for debugging, but avoid console.log in production
        const headersBefore = response.headersSent;

        let containment_result;
        try {
            containment_result = await containmentChecker.checkContainment(subquery, superquery);
        } catch (error) {
            if (!response.headersSent) {
                response.statusCode = 500;
                const errorResponse = JSON.stringify({ error: error });
                response.setHeader("Content-Length", Buffer.byteLength(errorResponse));
                response.write(errorResponse);
                response.end();
            }
            return;
        }

        const headersAfter = response.headersSent;
        if (headersBefore !== headersAfter) {
            // Temporary log to confirm headers change; remove after debugging
            console.log(`Headers changed during checkContainment: ${headersBefore} -> ${headersAfter}`);
        }

        if (!response.headersSent) {
            response.statusCode = 200;
            const jsonResponse = JSON.stringify({ containment: containment_result });
            response.setHeader("Content-Length", Buffer.byteLength(jsonResponse));
            response.write(jsonResponse);
            response.end();
        }
    }
}