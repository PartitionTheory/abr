#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_synth_set.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Math Deactivation Operator.
 *
 * Payload:
 *   { "family": "synth.math.basic" }
 */

static abr_synth_operator_t synth_math_deactivate_op = {
    .operator_id = 2005,
    .name = "synth.math.deactivate",
    .class_tag = "synth.math.deactivate"
};

static int synth_math_deactivate_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;
    const char* family = abr_json_min_get_string(json, "family");

    int rc = abr_synth_set_deactivate(ctx, family);

    free((void*)family);

    char payload[64];
    snprintf(payload, sizeof(payload), "{\"status\": %d}", rc);

    return abr_synth_execute(ctx, &synth_math_deactivate_op, payload);
}

void abr_synth_math_deactivate_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_math_deactivate_op.operator_id,
        .name = synth_math_deactivate_op.name,
        .execute = synth_math_deactivate_exec
    };

    abr_register_operator(ctx, &o);
}

