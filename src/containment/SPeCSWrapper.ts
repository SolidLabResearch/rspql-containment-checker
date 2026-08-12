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
import { constants, accessSync } from 'fs';
import { spawn, spawnSync, SpawnOptions } from 'child_process';

export interface SPeCSDiagnostics {
    executablePath: string;
    platform: NodeJS.Platform;
    architecture: string;
    source: 'argument' | 'environment' | 'bundled';
}

const supportedPlatforms = new Set(['darwin-arm64', 'linux-x64']);

/** Resolve and validate the executable built by this package's install hook. */
export function resolveSPeCSExecutable(executablePath?: string): SPeCSDiagnostics {
    const source = executablePath ? 'argument' : process.env.SPECS_EXECUTABLE ? 'environment' : 'bundled';
    const resolvedPath = path.resolve(
        executablePath ?? process.env.SPECS_EXECUTABLE ?? path.resolve(__dirname, '../../specs/src/specs')
    );
    const platformKey = `${process.platform}-${process.arch}`;

    if (!supportedPlatforms.has(platformKey)) {
        throw new Error(
            `Unsupported SPeCS platform ${platformKey}; supported platforms are macOS arm64 and Linux x86_64. ` +
            `Resolved executable: ${resolvedPath}.`
        );
    }

    try {
        accessSync(resolvedPath, constants.X_OK);
    } catch (error) {
        const reason = error instanceof Error ? error.message : String(error);
        throw new Error(
            `SPeCS executable is missing or not executable: ${resolvedPath} ` +
            `(platform=${process.platform}, arch=${process.arch}, source=${source}). ` +
            'Reinstall rspql-containment-checker so its install script can build SPeCS, or set SPECS_EXECUTABLE to a compatible executable. ' +
            `Underlying error: ${reason}`
        );
    }

    return { executablePath: resolvedPath, platform: process.platform, architecture: process.arch, source };
}

function ensureZ3Available(diagnostics: SPeCSDiagnostics): void {
    const result = spawnSync('z3', ['-version'], { stdio: 'ignore' });
    if (result.error || result.status !== 0) {
        throw new Error(
            `Z3 is required to run SPeCS but was not available on PATH ` +
            `(SPeCS=${diagnostics.executablePath}, platform=${diagnostics.platform}, arch=${diagnostics.architecture}). ` +
            'Install z3 and retry.'
        );
    }
}


/**
 * SPeCSWrapper is a class that provides a method to run the SPeCS tool for checking query containment.
 * It uses the child_process module to spawn a new process and execute the SPeCS tool with the provided options.
 * The class handles the process output and error streams, and returns the result of the containment check.
 * @class SPeCSWrapper
 */
export class SPeCSWrapper {
    /** Returns the executable identity used by a subsequent runSPeCS call. */
    public getDiagnostics(executablePath?: string): SPeCSDiagnostics {
        return resolveSPeCSExecutable(executablePath);
    }
    /**
     * Creates an instance of SPeCSWrapper.
     * @memberof SPeCSWrapper
     * @param {SpecsOptions} options - The options for the SPeCS tool.
     * @param {string} [executablePath] - Explicit compatible executable path; otherwise SPECS_EXECUTABLE or the bundled build is used.
     * @returns {Promise<SpecsResult>} - The result of the containment check.
     * @throws {Error} - Throws an error if the SPeCS tool fails to execute or if the containment result is null.
     * @memberof SPeCSWrapper
     */
    public async runSPeCS(options: SpecsOptions, executablePath?: string): Promise<SpecsResult> {
        if (!options.superquery || !options.subquery) {
            throw new Error("Both superquery and subquery are required.");
        }

        const diagnostics = this.getDiagnostics(executablePath);
        ensureZ3Available(diagnostics);

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

        const process = spawn(diagnostics.executablePath, args, spawnOptions);
                        
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
                reject(new Error(
                    `SPeCS could not execute ${diagnostics.executablePath} ` +
                    `(platform=${diagnostics.platform}, arch=${diagnostics.architecture}, source=${diagnostics.source}): ${error.message}`
                ));
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
