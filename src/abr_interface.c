/*
 * ABR-Rebirth: Interface Layer Implementation
 *
 * Implements operator metadata registration and interface-level execution
 * boundaries between core, VM, operators, and plugins.
 */

#include "abr_interface.h"
#include "abr_stream.h"
#include "abr_core.h"
#include "abr_operators.h"
#include "abr_vm.h"

#include <stdlib.h>

/* ------------------------------------------------------------------------- */
/* Operator metadata registration                                            */
/* ------------------------------------------------------------------------- */

int abr_register_operator(abr_runtime_t *rt, const abr_operator_info_t *info)
{
    if (!rt || !rt->initialized || !info) {
        return -1;
    }

    /* Delegate to internal operator subsystem */
    return abr_operator_register(rt,
                                 info->operator_id,
                                 NULL, /* function pointer will be wired later */
                                 info->name,
                                 info->gradient_cost,
                                 info->coherence_requirement);
}

const abr_operator_info_t *abr_get_operator_info(abr_runtime_t *rt, int operator_id)
{
    (void)rt;
    (void)operator_id;

    /* Metadata lookup will be implemented when operator tables are populated. */
    return NULL;
}

/* ------------------------------------------------------------------------- */
/* Interface-level execution wrapper                                         */
/* ------------------------------------------------------------------------- */

int abr_interface_execute(abr_context_t *ctx, int operator_id, void *args)
{
    if (!ctx || !ctx->runtime || !ctx->runtime->initialized) {
        return -1;
    }

    /* Interface-level invariants (gradient/coherence checks) will be added
     * once the corresponding fields are wired into the runtime and context. */

    /* Delegate actual execution to the VM. */
    return abr_vm_execute(ctx, operator_id, args);
}

abr_bitwindow abr_interface_window(abr_context_t* ctx, size_t offset, size_t length)
{
    abr_bitwindow w;
    w.data = NULL;
    w.length = 0;

    if (!ctx || !ctx->stream) {
        return w;
    }

    return abr_stream_window(ctx->stream, offset, length);
}
