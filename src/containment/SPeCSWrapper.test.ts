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

import { SpecsOptions } from "../types/Types";
import fs from 'fs';
import os from 'os';
import path from 'path';
import { resolveSPeCSExecutable, SPeCSWrapper } from "./SPeCSWrapper";

describe("SPeCSWrapper", () => {
    afterEach(() => {
        delete process.env.SPECS_EXECUTABLE;
    });

    it("resolves the deterministic bundled executable with diagnostics", () => {
        const diagnostics = resolveSPeCSExecutable();
        expect(diagnostics.executablePath).toMatch(/specs\/src\/specs$/);
        expect(diagnostics.platform).toBe(process.platform);
        expect(diagnostics.architecture).toBe(process.arch);
        expect(diagnostics.source).toBe('bundled');
    });

    it("uses an explicit environment override during resolution", () => {
        process.env.SPECS_EXECUTABLE = process.execPath;
        const diagnostics = resolveSPeCSExecutable();
        expect(diagnostics.executablePath).toBe(path.resolve(process.execPath));
        expect(diagnostics.source).toBe('environment');
    });

    it("fails clearly when the requested executable is absent", () => {
        expect(() => resolveSPeCSExecutable('/definitely/not/a/specs/executable')).toThrow(
            'SPeCS executable is missing or not executable'
        );
    });

    it("propagates a spawn failure instead of reporting ordinary non-containment", async () => {
        const temporaryDirectory = fs.mkdtempSync(path.join(os.tmpdir(), 'specs-wrapper-'));
        const wrapper = new SPeCSWrapper();
        try {
            await expect(wrapper.runSPeCS({ superquery: 'SELECT * WHERE {}', subquery: 'SELECT * WHERE {}' }, temporaryDirectory))
                .rejects.toThrow('SPeCS could not execute');
        } finally {
            fs.rmdirSync(temporaryDirectory);
        }
    });

    it("should throw an error if superquery or subquery is not provided", async () => {
        const wrapper = new SPeCSWrapper();
        await expect(wrapper.runSPeCS({ superquery: "", subquery: "" })).rejects.toThrow("Both superquery and subquery are required.");
    });

    it("should run SPeCS with valid options", async () => {
        const wrapper = new SPeCSWrapper();
        const options: SpecsOptions = {
            superquery: "PREFIX ex: <http://example.org/> SELECT ?x WHERE { ?x a ex:Person . }",
            subquery: "PREFIX ex: <http://example.org/> SELECT ?x WHERE { ?x a ex:Person . ?x ex:hasAge ex:One . }",
            rename: true,
            qc: true,
        };

        const result = await wrapper.runSPeCS(options);
        expect(result).toHaveProperty("containment");
    });

    it("check for simple containment", async () => {
        const wrapper = new SPeCSWrapper();
        const options: SpecsOptions = {
            superquery: "PREFIX ex: <http://example.org/> SELECT ?x WHERE { ?x a ex:Person .  }",
            subquery: "PREFIX ex: <http://example.org/> SELECT ?x WHERE { ?x a ex:Person . ?x ex:hasAge ex:One . }",
        };        
        const result = await wrapper.runSPeCS(options);
        expect(result.containment).toBe(true);
    })

    it("check for non-containment", async () => {
        const wrapper = new SPeCSWrapper();
        const options: SpecsOptions = {
            subquery: "PREFIX ex: <http://example.org/> SELECT ?x WHERE { ?x a ex:Person .  }",
            superquery: "PREFIX ex: <http://example.org/> SELECT ?x WHERE { ?x a ex:Person . ?x ex:hasAge ex:One . }",
        }

        const result = await wrapper.runSPeCS(options);
        expect(result.containment).toBe(false);
    });
});
