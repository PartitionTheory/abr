/*
 * ABR-Rebirth: Virtual Machine Execution Engine
 *
 * Implements VM initialization, shutdown, and operator execution.
 */

#include "abr_vm.h"
#include "abr_core.h"
#include "abr_interface.h"
#include "abr_operators.h"
#include "abr_dispatch.h"
#include "abr_plugin.h"

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */
/* VM lifecycle                                                              */
/* ------------------------------------------------------------------------- */

abr_vm_state_t *abr_vm_init(abr_runtime_t *rt)
{
    if (!rt || !rt->initialized) {
        return NULL;
    }

    abr_vm_state_t *vm = (abr_vm_state_t *)malloc(sizeof(abr_vm_state_t));
    if (!vm) {
        return NULL;
    }

    memset(vm, 0, sizeof(*vm));

    vm->operator_dispatch = NULL;   /* Will be populated by operator subsystem */
    vm->reverse_stack     = NULL;   /* Reversible execution stack (future)     */
    vm->reverse_stack_size = 0;

    vm->gradient_limit    = 0;
    vm->coherence_mode    = 0;

    return vm;
}

void abr_vm_shutdown(abr_vm_state_t *vm)
{
    if (!vm) {
        return;
    }

    /* Reverse stack cleanup will be added later */
    free(vm);
}

/* ------------------------------------------------------------------------- */
/* Operator execution                                                         */
/* ------------------------------------------------------------------------- */

int abr_vm_execute(abr_context_t *ctx, int operator_id, void *args)
{
    if (!ctx || !ctx->runtime || !ctx->runtime->initialized) {
        return -1;
    }

    abr_runtime_t *rt = ctx->runtime;

    /* Lookup operator entry */
    const abr_operator_entry_t *entry =
        abr_operator_lookup(rt, operator_id);

    if (!entry || !entry->fn) {
        return -2; /* Operator not found */
    }

    /* Gradient/coherence enforcement will be added later */

    /* Execute operator */
    int result = entry->fn(ctx, args);

    /* Reversible execution bookkeeping will be added later */

    return result;
}

abr_plugin_result abr_vm_exec_plugin_by_class(abr_context_t* ctx, const char* class_tag, const char* json)
{
    if (!ctx || !class_tag) {
        return (abr_plugin_result){
            .status = 0,
            .message = "invalid VM context or class_tag",
            .json = "{}"
        };
    }

    return abr_dispatch_plugin_by_class(ctx, class_tag, json);
}
