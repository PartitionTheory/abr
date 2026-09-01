#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Reset Operator.
 *
 * Fully resets VM state.
 */

static abr_synth_operator_t synth_vm_reset_op = {
    .operator_id = 3003,
    .name = "synth.vm.reset",
    .class_tag = "synth.vm.reset"
};

static int synth_vm_reset_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    abr_vm_reset(ctx);

    const char* payload = "{ \"vm\": \"reset\" }";

    return abr_synth_execute(ctx, &synth_vm_reset_op, payload);
}

void abr_synth_vm_reset_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_reset_op.operator_id,
        .name = synth_vm_reset_op.name,
        .execute = synth_vm_reset_exec
    };

    abr_register_operator(ctx, &o);
}

