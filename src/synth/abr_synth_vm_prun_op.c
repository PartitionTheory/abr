#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program Run Operator.
 *
 * Executes the currently loaded program and returns the execution trace.
 */

static abr_synth_operator_t synth_vm_prun_op = {
    .operator_id = 3014,
    .name = "synth.vm.prun",
    .class_tag = "synth.vm.prun"
};

static int synth_vm_prun_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    const char* json = abr_vm_program_run(ctx);

    return abr_synth_execute(ctx, &synth_vm_prun_op, json);
}

void abr_synth_vm_prun_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_prun_op.operator_id,
        .name = synth_vm_prun_op.name,
        .execute = synth_vm_prun_exec
    };

    abr_register_operator(ctx, &o);
}

