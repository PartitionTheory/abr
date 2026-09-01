#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Instruction List Operator.
 *
 * Returns:
 *   { "instructions": [ ... ] }
 */

static abr_synth_operator_t synth_vm_ilist_op = {
    .operator_id = 3006,
    .name = "synth.vm.ilist",
    .class_tag = "synth.vm.ilist"
};

static int synth_vm_ilist_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    const char* list_json = abr_vm_instruction_list(ctx);

    return abr_synth_execute(ctx, &synth_vm_ilist_op, list_json);
}

void abr_synth_vm_ilist_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_ilist_op.operator_id,
        .name = synth_vm_ilist_op.name,
        .execute = synth_vm_ilist_exec
    };

    abr_register_operator(ctx, &o);
}

