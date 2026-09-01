#include "abr_exec.h"
#include "abr_plugin_loader.h"
#include "abr_plugin.h"

/*
 * ABR‑Rebirth: Operator Dispatch Implementation
 * ---------------------------------------------
 * Phase 4 Step 05
 *
 * This file provides the initial dispatch logic that selects
 * the correct execution path for an operator. Later steps will
 * expand this with plugin operator routing, synthetic math
 * classification, and reversible execution heuristics.
 */
#include "abr_core.h"

int abr_dispatch(abr_context_t *ctx, int operator_id, void *args)
{
    if (!ctx) {
        return -1;
    }

    /* Placeholder dispatch logic (Phase 4 Step 05). */
    /* Future: classify operator type and route accordingly. */

    /* Default: direct execution through abr_exec. */
    return abr_exec_by_id(ctx, operator_id, args);
}

abr_plugin_result abr_dispatch_plugin_by_class(abr_context_t* ctx, const char* class_tag, const char* json)
{
    (void)ctx; /* unused in v0.4-greenbuild */

    if (!class_tag) {
        return (abr_plugin_result){ .status = 0, .message = "null class_tag", .json = "{}" };
    }

    abr_plugin* p = abr_plugin_load_by_class(class_tag);
    if (!p) {
        return (abr_plugin_result){ .status = 0, .message = "plugin not found", .json = "{}" };
    }

    abr_plugin_input input = { .json = json ? json : "{}" };
    return p->execute(&input);
}
