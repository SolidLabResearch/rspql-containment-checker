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

export class SPeCSWrapper {
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
            if (output === 'unsat') containment = true;
            else if (output === 'sat - 0') containment = false;
            else containment = null;
        } else {
            throw new Error(`SPeCS process exited with code ${exitCode}: ${stderr}`);
        }

        return { stdout, stderr, exitCode, containment };
    }
}