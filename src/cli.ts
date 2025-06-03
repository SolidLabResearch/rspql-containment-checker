#!/usr/bin/env node
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

import { HTTPServer } from "./server/HTTPServer";
import * as bunyan from "bunyan";
import * as fs from 'fs';
import { program } from "commander";

/**
 * This function generates a timestamp string in the format YYYY-MM-DD-HH-mm-ss.
 * @function getTimestamp
 * @returns {string} - The timestamp string.
 */
function getTimestamp() {
  const now = new Date();
  return `${now.getFullYear()}-${(now.getMonth() + 1).toString().padStart(2, '0')}-${now.getDate().toString().padStart(2, '0')}-${now.getHours().toString().padStart(2, '0')}-${now.getMinutes().toString().padStart(2, '0')}-${now.getSeconds().toString().padStart(2, '0')}`;
}

const copyrightNotice = `
    Copyright (C) 2025 Kush Bisen (UGent - imec).
    This program comes with ABSOLUTELY NO WARRANTY; 
    This is free software, and you are welcome to redistribute it
    under certain conditions as specified in the GNU General Public License.
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program. If not, see <https://www.gnu.org/licenses/>.
`;

const log_file = fs.createWriteStream(`aggregator-${getTimestamp()}.log`, { flags: 'a' });
const logger = bunyan.createLogger({
  name: "RSPQL-Containment-Checker",
  streams: [
    {
      level: 'info',
      stream: log_file
    },
  ],
  serializers: {
    log: (log_data: any) => {
      return {
        ...log_data,
        query_id: log_data.query_id || 'no_query_id',
      }
    }
  }
});


program
  .version("1.0.0")
  .description("Checker for containment relations in between two different RSPQL queries")
  .name("RSPQL-Containment-Checker")
  .command("containment-checker")
  .option("-p, --port <port>", "Port to run the server on", "8085")
  .action(async (options: { port: number }) => {
    console.log(copyrightNotice);
    console.log(`Starting RSPQL Containment Checker on port ${options.port}`);
    new HTTPServer(options.port, logger)
  });

  program.parse();