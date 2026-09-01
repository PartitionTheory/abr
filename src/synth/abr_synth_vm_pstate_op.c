#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program State Operator.
 *
 * Returns the current VM state after program execution.
 */

static abr_synth_operator_t synth_vm_pstate_op = {
    .operator_id = 3015,
    .name = "synth.vm.pstate",
    .class_tag = "synth.vm.pstate"
};

static int synth_vm_pstate_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    const char* json = abr_vm_program_state(ctx);

    return abr_synth_execute(ctx, &synth_vm_pstate_op, json);
}

void abr_synth_vm_pstate_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_pstate_op.operator_id,
        .name = synth_vm_pstate_op.name,
        .execute = synth_vm_pstate_exec
    };

    abr_register_operator(ctx, &o);
}

