#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Program Definition Operator.
 *
 * Payload:
 *   {
 *     "name": "myprog",
 *     "pipe": [ ... ]
 *   }
 */

static abr_synth_operator_t synth_prog_define_op = {
    .operator_id = 2011,
    .name = "synth.prog.define",
    .class_tag = "synth.prog.define"
};

static int synth_prog_define_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    const char* name = abr_json_min_get_string(json, "name");
    const char* pipe = abr_json_min_get_string(json, "pipe");

    abr_synth_program_define(ctx, name, pipe);

    free((void*)name);
    free((void*)pipe);

    const char* payload = "{ \"defined\": 1 }";

    return abr_synth_execute(ctx, &synth_prog_define_op, payload);
}

void abr_synth_prog_define_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_prog_define_op.operator_id,
        .name = synth_prog_define_op.name,
        .execute = synth_prog_define_exec
    };

    abr_register_operator(ctx, &o);
}

