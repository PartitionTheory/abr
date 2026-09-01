#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Instruction Metadata Operator.
 *
 * Returns metadata for a single instruction.
 */

static abr_synth_operator_t synth_vm_imeta_op = {
    .operator_id = 3007,
    .name = "synth.vm.imeta",
    .class_tag = "synth.vm.imeta"
};

static int synth_vm_imeta_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    const char* instr = abr_json_min_get_string(json, "instruction");

    const char* meta_json = abr_vm_instruction_metadata(ctx, instr);

    free((void*)instr);

    return abr_synth_execute(ctx, &synth_vm_imeta_op, meta_json);
}

void abr_synth_vm_imeta_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_imeta_op.operator_id,
        .name = synth_vm_imeta_op.name,
        .execute = synth_vm_imeta_exec
    };

    abr_register_operator(ctx, &o);
}

