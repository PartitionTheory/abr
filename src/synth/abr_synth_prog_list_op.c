#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Program List Operator.
 *
 * Returns:
 *   { "programs": [ ... ] }
 */

static abr_synth_operator_t synth_prog_list_op = {
    .operator_id = 2014,
    .name = "synth.prog.list",
    .class_tag = "synth.prog.list"
};

static int synth_prog_list_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    const char* list_json = abr_synth_program_list(ctx);

    return abr_synth_execute(ctx, &synth_prog_list_op, list_json);
}

void abr_synth_prog_list_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_prog_list_op.operator_id,
        .name = synth_prog_list_op.name,
        .execute = synth_prog_list_exec
    };

    abr_register_operator(ctx, &o);
}

