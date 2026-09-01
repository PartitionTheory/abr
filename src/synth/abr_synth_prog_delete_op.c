#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Program Delete Operator.
 *
 * Payload:
 *   {
 *     "name": "myprog"
 *   }
 */

static abr_synth_operator_t synth_prog_delete_op = {
    .operator_id = 2013,
    .name = "synth.prog.delete",
    .class_tag = "synth.prog.delete"
};

static int synth_prog_delete_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    const char* name = abr_json_min_get_string(json, "name");

    int rc = abr_synth_program_delete(ctx, name);

    free((void*)name);

    char payload[64];
    snprintf(payload, sizeof(payload),
        "{ \"deleted\": %d }",
        rc ? 1 : 0
    );

    return abr_synth_execute(ctx, &synth_prog_delete_op, payload);
}

void abr_synth_prog_delete_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_prog_delete_op.operator_id,
        .name = synth_prog_delete_op.name,
        .execute = synth_prog_delete_exec
    };

    abr_register_operator(ctx, &o);
}

