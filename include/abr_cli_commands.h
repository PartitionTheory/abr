/*
 * ABR‑Rebirth: CLI Command Extensions (Phase 4 Step 07)
 * -----------------------------------------------------
 * This module defines the command handlers that expose
 * Phase 4 dynamic behavior through the ABR CLI.
 */

#include "abr_dispatch.h"
#include "abr_plugin_loader.h"
#include "abr_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Execute an operator by name from the CLI. */
int abr_cli_cmd_run(abr_runtime_t *rt, const char *name);

/* Load a plugin from the CLI. */
int abr_cli_cmd_plugin_load(abr_runtime_t *rt, const char *path);

/* Unload a plugin from the CLI. */
int abr_cli_cmd_plugin_unload(abr_runtime_t *rt, const char *path);

/* Display runtime information. */
int abr_cli_cmd_info(abr_runtime_t *rt);

#ifdef __cplusplus
}
#endif

#endif /* ABR_CLI_COMMANDS_H */
