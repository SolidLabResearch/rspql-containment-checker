#!/usr/bin/env node
/* Build the native SPeCS executable for the installing host. */
const { existsSync } = require('fs');
const { spawnSync } = require('child_process');
const path = require('path');

const supportedPlatforms = new Set(['darwin-arm64', 'linux-x64']);
const platformKey = `${process.platform}-${process.arch}`;
const sourceDirectory = path.resolve(__dirname, '..', 'specs', 'src');
const executable = path.join(sourceDirectory, 'specs');
const generatedSources = ['parser.tab.cpp', 'parser.tab.hpp', 'lex.yy.c'];

if (!supportedPlatforms.has(platformKey)) {
    throw new Error(
        `Unsupported SPeCS build platform ${platformKey}. Supported platforms: macOS arm64 and Linux x86_64.`
    );
}

for (const source of generatedSources) {
    if (!existsSync(path.join(sourceDirectory, source))) {
        throw new Error(
            `Cannot build SPeCS: generated source ${source} is missing from ${sourceDirectory}. ` +
            'Install flex and bison, restore the generated source, then retry npm install.'
        );
    }
}

const result = spawnSync('make', ['-C', sourceDirectory, 'clean-build', 'specs'], { stdio: 'inherit' });
if (result.error) {
    throw new Error(
        `Cannot build SPeCS for ${platformKey}: failed to start make (${result.error.message}). ` +
        'Install make and g++, then retry npm install.'
    );
}
if (result.status !== 0 || !existsSync(executable)) {
    throw new Error(
        `SPeCS build failed for ${platformKey} (make exit ${result.status ?? 'unknown'}). ` +
        'Install make and g++, then retry npm install.'
    );
}

console.log(`Built SPeCS executable for ${platformKey}: ${executable}`);
