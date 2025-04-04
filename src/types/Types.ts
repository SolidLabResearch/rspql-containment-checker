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

/**
 * Interface representing the options for the specs command.
 * The options include:
 * - `superquery`: The superquery to be used.
 * - `subquery`: The subquery to be used.
 * - `schema`: The schema to be used (optional).
 * - `rename`: The rename option (optional).
 * - `qc`: The quality control option (optional).
 * @export
 * @interface SpecsOptions
 */
export interface SpecsOptions {
    superquery: string;
    subquery: string;
    schema?: string;
    rename?: string;
    qc?: string;
}

/**
 * Interface representing the result of the specs command.
 * The result includes:
 * - `stdout`: The standard output of the command.
 * - `stderr`: The standard error of the command.
 * - `exitCode`: The exit code of the command.
 * - `containment`: A boolean indicating whether the containment was successful or not (optional).
 * The `containment` property is optional and can be null if not applicable.
 * @export
 * @interface SpecsResult
 */
export interface SpecsResult {
    stdout: string;
    stderr: string;
    exitCode: number;
    containment: boolean | null;
}

/**
 * Interface representing the API response.
 * The response includes:
 * - `success`: A boolean indicating whether the request was successful or not.
 * - `data`: An object containing the result of the command (optional).
 * - `error`: A string containing the error message (optional).
 * @export
 * @interface ApiResponse
 */
export interface ApiResponse {
    success: boolean;
    data?: {
        containment: boolean | null;
        stdout: string;
        stderr: string;
        exitCode: number;
    };
    error?: string;
}