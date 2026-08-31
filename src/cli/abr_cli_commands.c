#include "abr_cli_commands.h"
#include <stdio.h>

/*
 * ABR‑Rebirth: CLI Command Extensions Implementation
 * --------------------------------------------------
 * Phase 4 Step 07
 *
 * This file provides the initial implementation of CLI commands
 * that expose Phase 4 dynamic behavior: operator execution,
 * plugin loading, plugin unloading, and runtime information.
 */

int abr_cli_cmd_run(abr_runtime_t *rt, const char *name)
{
    if (!rt || !name) {
        return -1;
    }

    /* Dispatch operator by name. */
    return abr_dispatch(rt->context, rt->get_operator_id(rt, name), NULL);
}

int abr_cli_cmd_plugin_load(abr_runtime_t *rt, const char *path)
{
    if (!rt || !path) {
        return -1;
    }

    return abr_plugin_loader_load(rt, path);
}

int abr_cli_cmd_plugin_unload(abr_runtime_t *rt, const char *path)
{
    if (!rt || !path) {
        return -1;
    }

    return abr_plugin_loader_unload(rt, path);
}

int abr_cli_cmd_info(abr_runtime_t *rt)
{
    if (!rt) {
        return -1;
    }

    printf("ABR Runtime Info:\n");
    printf("Operators: %d\n", rt->operator_count);
    printf("Plugins: %d\n", rt->plugin_count);

    return 0;
}
