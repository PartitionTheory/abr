#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Pipeline Reset Operator.
 *
 * Clears last pipeline execution state.
 */

static abr_synth_operator_t synth_pipe_reset_op = {
    .operator_id = 2010,
    .name = "synth.pipe.reset",
    .class_tag = "synth.pipe.reset"
};

static int synth_pipe_reset_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    abr_synth_reset_last_pipe(ctx);

    const char* payload = "{ \"reset\": 1 }";

    return abr_synth_execute(ctx, &synth_pipe_reset_op, payload);
}

void abr_synth_pipe_reset_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_pipe_reset_op.operator_id,
        .name = synth_pipe_reset_op.name,
        .execute = synth_pipe_reset_exec
    };

    abr_register_operator(ctx, &o);
}

