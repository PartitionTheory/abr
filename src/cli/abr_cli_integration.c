#include "abr_cli_commands.h"
#include "abr_cli.h"

/*
 * ABR‑Rebirth: CLI Integration & Wiring
 * -------------------------------------
 * Phase 4 Step 08
 *
 * This file connects the Phase 4 CLI command extensions to the
 * existing Phase 3 CLI parser. It enables dynamic operator execution,
 * plugin loading/unloading, and runtime introspection through the
 * ABR command-line interface.
 *
 * This step does not modify any Phase 1–3 files. It is a pure
 * Phase 4 additive integration layer.
 */

int abr_cli_integrate(abr_runtime_t *rt, const char *cmd, const char *arg)
{
    if (!rt || !cmd) {
        return -1;
    }

    /* Operator execution */
    if (strcmp(cmd, "run") == 0 && arg) {
        return abr_cli_cmd_run(rt, arg);
    }

    /* Plugin load */
    if (strcmp(cmd, "plugin-load") == 0 && arg) {
        return abr_cli_cmd_plugin_load(rt, arg);
    }

    /* Plugin unload */
    if (strcmp(cmd, "plugin-unload") == 0 && arg) {
        return abr_cli_cmd_plugin_unload(rt, arg);
    }

    /* Runtime info */
    if (strcmp(cmd, "info") == 0) {
        return abr_cli_cmd_info(rt);
    }

    /* Unknown command */
    return -1;
}

