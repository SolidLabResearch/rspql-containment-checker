export interface SpecsOptions {
    superquery: string;
    subquery: string;
    schema?: string;
    rename?: string;
    qc?: string;
}

export interface SpecsResult {
    stdout: string;
    stderr: string;
    exitCode: number;
    containment: boolean | null;
}

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