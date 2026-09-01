#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Status Operator.
 *
 * Reports VM state.
 */

static abr_synth_operator_t synth_vm_status_op = {
    .operator_id = 3004,
    .name = "synth.vm.status",
    .class_tag = "synth.vm.status"
};

static int synth_vm_status_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    char payload[256];
    snprintf(payload, sizeof(payload),
        "{ \"pc\": %d, \"halted\": %d, \"error\": %d, \"steps\": %d, \"residue\": %d }",
        ctx->vm.pc,
        ctx->vm.halted,
        ctx->vm.error,
        ctx->vm.steps,
        ctx->vm.residue
    );

    return abr_synth_execute(ctx, &synth_vm_status_op, payload);
}

void abr_synth_vm_status_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_status_op.operator_id,
        .name = synth_vm_status_op.name,
        .execute = synth_vm_status_exec
    };

    abr_register_operator(ctx, &o);
}

