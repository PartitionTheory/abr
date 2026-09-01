#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program Reset Operator.
 *
 * Resets VM state while keeping the loaded program.
 */

static abr_synth_operator_t synth_vm_preset_op = {
    .operator_id = 3016,
    .name = "synth.vm.preset",
    .class_tag = "synth.vm.preset"
};

static int synth_vm_preset_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    int rc = abr_vm_program_reset(ctx);

    const char* json = rc == 0
        ? "{ \"reset\": true, \"pc\": 0, \"stack_depth\": 0, \"cycles\": 0 }"
        : "{ \"reset\": false, \"error\": true }";

    return abr_synth_execute(ctx, &synth_vm_preset_op, json);
}

void abr_synth_vm_preset_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_preset_op.operator_id,
        .name = synth_vm_preset_op.name,
        .execute = synth_vm_preset_exec
    };

    abr_register_operator(ctx, &o);
}

