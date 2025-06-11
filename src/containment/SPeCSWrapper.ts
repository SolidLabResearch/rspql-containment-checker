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

import { SpecsOptions, SpecsResult } from "../types/Types";
import path from 'path';
import { spawn, SpawnOptions } from 'child_process';


/**
 * SPeCSWrapper is a class that provides a method to run the SPeCS tool for checking query containment.
 * It uses the child_process module to spawn a new process and execute the SPeCS tool with the provided options.
 * The class handles the process output and error streams, and returns the result of the containment check.
 * @class SPeCSWrapper
 */
export class SPeCSWrapper {
    /**
     * Creates an instance of SPeCSWrapper.
     * @memberof SPeCSWrapper
     * @param {SpecsOptions} options - The options for the SPeCS tool.
     * @param {string} [executablePath=path.resolve(__dirname, '../../specs/src/specs')] - The path to the SPeCS C++ executable.
     * @returns {Promise<SpecsResult>} - The result of the containment check.
     * @throws {Error} - Throws an error if the SPeCS tool fails to execute or if the containment result is null.
     * @memberof SPeCSWrapper
     */
    public async runSPeCS(options: SpecsOptions, executablePath: string = path.resolve(__dirname, '../../specs/src/specs')): Promise<SpecsResult> {
        if (!options.superquery || !options.subquery) {
            throw new Error("Both superquery and subquery are required.");
        }

        const args: string[] = [
            '-superquery', options.superquery,
            '-subquery', options.subquery,
        ];

        if (options.schema) args.push('-schema', options.schema);
        if (options.rename) args.push('-rename');
        if (options.qc) args.push('-qc');

        const spawnOptions: SpawnOptions = {
            stdio: ['pipe', 'pipe', 'pipe'],
        };

        const process = spawn(executablePath, args, spawnOptions);
                        
        let stdout = '';
        let stderr = '';

        process.stdout?.on('data', (data: Buffer) => {
            stdout += data.toString();
        });

        process.stderr?.on('data', (data: Buffer) => {
            stderr += data.toString();
        });

        const waitforExit = new Promise<number>((resolve, reject) => {
            const timeout = setTimeout(() => reject(new Error('Process timeout after 30 seconds')), 30000);
            process.on('error', (error) => {
                clearTimeout(timeout);
                reject(error);
            });

            process.on('exit', (code) => {
                clearTimeout(timeout);
                resolve(code ?? 1);
            });
        });

        const exitCode = await waitforExit;

        let containment: boolean | null = null;        
        if (exitCode === 0) {
            const output = stdout.trim().toLowerCase();
            // SPeCS returns 'sat - 1' for containment true, 'sat - 0' for false, 'unsat' for true in some configs
            if (output.startsWith('sat - 1')) containment = true;
            else if (output.startsWith('sat - 0')) containment = false;
            else if (output.startsWith('unsat')) containment = true;
            else containment = null;
        } else {
            throw new Error(`SPeCS process exited with code ${exitCode}: ${stderr}`);
        }

        return { stdout, stderr, exitCode, containment };
    }       
}