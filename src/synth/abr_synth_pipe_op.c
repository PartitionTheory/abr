#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Pipeline Operator.
 *
 * Payload:
 *   {
 *     "pipe": [
 *       { "op": "synth.math.add", "args": "{...}" },
 *       { "op": "synth.math.mul", "args": "{...}" }
 *     ]
 *   }
 */

static abr_synth_operator_t synth_pipe_op = {
    .operator_id = 2008,
    .name = "synth.pipe",
    .class_tag = "synth.pipe"
};

static int synth_pipe_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    size_t count = abr_json_min_get_array_size(json, "pipe");

    int last_rc = 0;

    for (size_t i = 0; i < count; i++) {
        const char* op_name = abr_json_min_get_array_string(json, "pipe", i, "op");
        const char* op_args = abr_json_min_get_array_string(json, "pipe", i, "args");

        last_rc = abr_synth_call(ctx, op_name, op_args);

        free((void*)op_name);
        free((void*)op_args);

        if (last_rc != 0)
            break;
    }

    char payload[64];
    snprintf(payload, sizeof(payload), "{\"status\": %d}", last_rc);

    return abr_synth_execute(ctx, &synth_pipe_op, payload);
}

void abr_synth_pipe_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_pipe_op.operator_id,
        .name = synth_pipe_op.name,
        .execute = synth_pipe_exec
    };

    abr_register_operator(ctx, &o);
}

