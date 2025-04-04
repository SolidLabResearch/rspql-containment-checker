export async function ensurePromiseProperlyResolves() {
    await new Promise(resolve => setTimeout(resolve, 0));
}