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

import { IncomingMessage, ServerResponse } from "http";


/**
 * GETHandler is a class that handles incoming GET requests to the server.
 * It is responsible for processing the request and sending the appropriate response.
 * The class provides a static method handle that takes the request and response objects as parameters.
 * @class GETHandler
 */
export class GETHandler {


/**
 * Handles incoming GET requests to the server.
 * @static
 * @param {IncomingMessage} request - The incoming request object.
 * @param {ServerResponse} response - The response object to send the response.
 * @returns {Promise<void>} - A promise that resolves when the response has been sent.
 * @memberof GETHandler
 */
public static async handle(request: IncomingMessage, response: ServerResponse) {

    }
}