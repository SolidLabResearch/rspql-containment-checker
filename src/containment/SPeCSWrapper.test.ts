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
import { SPeCSWrapper } from "./SPeCSWrapper";

describe("SPeCSWrapper", () => {
    it("should throw an error if superquery or subquery is not provided", async () => {
        const wrapper = new SPeCSWrapper();
        await expect(wrapper.runSPeCS({ superquery: "", subquery: "" })).rejects.toThrow("Both superquery and subquery are required.");
    });

    it("should run SPeCS with valid options", async () => {
        const wrapper = new SPeCSWrapper();
        const options: SpecsOptions = {
            superquery: "superquery",
            subquery: "subquery",
            schema: "schema",
            rename: "true",
            qc: "true",
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