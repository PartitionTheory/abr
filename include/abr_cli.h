#ifndef ABR_CLI_H
#define ABR_CLI_H

/*
 * ABR-Rebirth: Command-Line Interface
 * Internal header — used by the abr executable.
 *
 * The CLI provides:
 *   - runtime initialization
 *   - plugin loading
 *   - operator execution from user commands
 *   - structural mathematics output formatting
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_context abr_context_t;

/*
 * Initialize CLI runtime.
 * Returns pointer to runtime or NULL on failure.
 */
abr_runtime_t *abr_cli_init(void);

/*
 * Shut down CLI runtime.
 */
void abr_cli_shutdown(abr_runtime_t *rt);

/*
 * Execute a single CLI command.
 * Returns 0 on success, non-zero on failure.
 */
int abr_cli_execute(abr_context_t *ctx, const char *command);

/*
 * Print a structural mathematics result to stdout.
 */
void abr_cli_print(const char *msg);

#ifdef __cplusplus
}
#endif

#endif /* ABR_CLI_H */

