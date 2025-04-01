import { HTTPServer } from "./server/HTTPServer";
import * as bunyan from "bunyan";
import * as fs from 'fs';
import { program } from "commander";

function getTimestamp() {
  const now = new Date();
  return `${now.getFullYear()}-${(now.getMonth() + 1).toString().padStart(2, '0')}-${now.getDate().toString().padStart(2, '0')}-${now.getHours().toString().padStart(2, '0')}-${now.getMinutes().toString().padStart(2, '0')}-${now.getSeconds().toString().padStart(2, '0')}`;
}

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
    console.log(`Starting RSPQL Containment Checker on port ${options.port}`);
    
    new HTTPServer(options.port, logger)
  });

  program.parse();
