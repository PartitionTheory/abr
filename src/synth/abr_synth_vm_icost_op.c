#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Instruction Cost Operator.
 *
 * Returns cost model for a single instruction.
 */

static abr_synth_operator_t synth_vm_icost_op = {
    .operator_id = 3009,
    .name = "synth.vm.icost",
    .class_tag = "synth.vm.icost"
};

static int synth_vm_icost_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    const char* instr = abr_json_min_get_string(json, "instruction");

    const char* cost_json = abr_vm_instruction_cost(ctx, instr);

    free((void*)instr);

    return abr_synth_execute(ctx, &synth_vm_icost_op, cost_json);
}

void abr_synth_vm_icost_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_icost_op.operator_id,
        .name = synth_vm_icost_op.name,
        .execute = synth_vm_icost_exec
    };

    abr_register_operator(ctx, &o);
}

