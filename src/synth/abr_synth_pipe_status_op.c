#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Pipeline Status Operator.
 *
 * Returns information about the last pipeline execution.
 */

static abr_synth_operator_t synth_pipe_status_op = {
    .operator_id = 2009,
    .name = "synth.pipe.status",
    .class_tag = "synth.pipe.status"
};

static int synth_pipe_status_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    abr_synth_pipe_info_t info;
    abr_synth_get_last_pipe_info(ctx, &info);

    char payload[256];
    snprintf(payload, sizeof(payload),
        "{ \"steps\": %zu, \"last_op\": \"%s\", \"last_status\": %d, \"completed\": %d }",
        info.steps,
        info.last_op ? info.last_op : "",
        info.last_status,
        info.completed
    );

    return abr_synth_execute(ctx, &synth_pipe_status_op, payload);
}

void abr_synth_pipe_status_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_pipe_status_op.operator_id,
        .name = synth_pipe_status_op.name,
        .execute = synth_pipe_status_exec
    };

    abr_register_operator(ctx, &o);
}

