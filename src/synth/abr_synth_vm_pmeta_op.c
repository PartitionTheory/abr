#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program Metadata Operator.
 *
 * Returns metadata for the currently loaded program.
 */

static abr_synth_operator_t synth_vm_pmeta_op = {
    .operator_id = 3013,
    .name = "synth.vm.pmeta",
    .class_tag = "synth.vm.pmeta"
};

static int synth_vm_pmeta_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    const char* json = abr_vm_program_metadata(ctx);

    return abr_synth_execute(ctx, &synth_vm_pmeta_op, json);
}

void abr_synth_vm_pmeta_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_pmeta_op.operator_id,
        .name = synth_vm_pmeta_op.name,
        .execute = synth_vm_pmeta_exec
    };

    abr_register_operator(ctx, &o);
}

