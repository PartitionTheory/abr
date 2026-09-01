#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program Step Operator.
 *
 * Executes exactly one instruction of the loaded program.
 */

static abr_synth_operator_t synth_vm_pstep_op = {
    .operator_id = 3017,
    .name = "synth.vm.pstep",
    .class_tag = "synth.vm.pstep"
};

static int synth_vm_pstep_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    const char* json = abr_vm_program_step(ctx);

    return abr_synth_execute(ctx, &synth_vm_pstep_op, json);
}

void abr_synth_vm_pstep_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_pstep_op.operator_id,
        .name = synth_vm_pstep_op.name,
        .execute = synth_vm_pstep_exec
    };

    abr_register_operator(ctx, &o);
}

