#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Halt Operator.
 *
 * Halts VM execution.
 */

static abr_synth_operator_t synth_vm_halt_op = {
    .operator_id = 3002,
    .name = "synth.vm.halt",
    .class_tag = "synth.vm.halt"
};

static int synth_vm_halt_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    abr_vm_halt(ctx);

    const char* payload = "{ \"vm\": \"halted\" }";

    return abr_synth_execute(ctx, &synth_vm_halt_op, payload);
}

void abr_synth_vm_halt_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_halt_op.operator_id,
        .name = synth_vm_halt_op.name,
        .execute = synth_vm_halt_exec
    };

    abr_register_operator(ctx, &o);
}

