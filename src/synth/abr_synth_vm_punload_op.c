#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program Unload Operator.
 *
 * Unloads the currently loaded program.
 */

static abr_synth_operator_t synth_vm_punload_op = {
    .operator_id = 3011,
    .name = "synth.vm.punload",
    .class_tag = "synth.vm.punload"
};

static int synth_vm_punload_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    int rc = abr_vm_program_unload(ctx);

    const char* payload = rc == 0
        ? "{ \"program_loaded\": false }"
        : "{ \"program_loaded\": false, \"error\": true }";

    return abr_synth_execute(ctx, &synth_vm_punload_op, payload);
}

void abr_synth_vm_punload_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_punload_op.operator_id,
        .name = synth_vm_punload_op.name,
        .execute = synth_vm_punload_exec
    };

    abr_register_operator(ctx, &o);
}

