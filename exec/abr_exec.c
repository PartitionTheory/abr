/*
 * ABR‑Rebirth: Execution Layer Implementation
 * -------------------------------------------
 * Phase 4 Step 01: Basic operator execution routing.
 *
 * This file implements the initial execution functions that
 * bridge operator metadata lookup with interface‑level VM
 * execution. Later Phase 4 steps will extend this with
 * reversible semantics and synthetic math.
 */
#include "abr_core.h"
#include "abr_interface.h"
#include <string.h>

int abr_exec_by_name(abr_context_t *ctx, const char *name, void *args)
{
    if (!ctx || !name) {
        return -1;
    }

    abr_runtime_t *rt = ctx->runtime;
    if (!rt) {
        return -1;
    }

    /* Linear search through operator registry (Phase 4 Step 01). */
    for (int i = 0; i < rt->operator_count; i++) {
        const abr_operator_info_t *info = rt->operators[i];
        if (info && info->name && strcmp(info->name, name) == 0) {
            return abr_interface_execute(ctx, info->operator_id, args);
        }
    }

    return -1; /* Operator not found */
}

int abr_exec_by_id(abr_context_t *ctx, int operator_id, void *args)
{
    if (!ctx) {
        return -1;
    }

    return abr_interface_execute(ctx, operator_id, args);
}
