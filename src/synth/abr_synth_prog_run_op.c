#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Program Run Operator.
 *
 * Payload:
 *   {
 *     "name": "myprog"
 *   }
 */

static abr_synth_operator_t synth_prog_run_op = {
    .operator_id = 2012,
    .name = "synth.prog.run",
    .class_tag = "synth.prog.run"
};

static int synth_prog_run_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    const char* name = abr_json_min_get_string(json, "name");

    const char* pipe = abr_synth_program_get(ctx, name);

    free((void*)name);

    if (!pipe)
        return abr_synth_execute(ctx, &synth_prog_run_op, "{ \"status\": -1 }");

    int rc = abr_synth_call(ctx, "synth.pipe", pipe);

    char payload[64];
    snprintf(payload, sizeof(payload), "{ \"status\": %d }", rc);

    return abr_synth_execute(ctx, &synth_prog_run_op, payload);
}

void abr_synth_prog_run_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_prog_run_op.operator_id,
        .name = synth_prog_run_op.name,
        .execute = synth_prog_run_exec
    };

    abr_register_operator(ctx, &o);
}

