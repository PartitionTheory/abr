#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Math Operator #2 — Multiplication.
 *
 * This operator accepts a JSON payload:
 *   { "a": <int>, "b": <int> }
 * and computes a * b.
 */

static abr_synth_operator_t synth_math_mul_op = {
    .operator_id = 2002,
    .name = "synth.math.mul",
    .class_tag = "synth.math.mul"
};

/*
 * Unified execution wrapper (Step 39).
 */
static int synth_math_mul_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    int a = abr_json_min_get_int(json, "a");
    int b = abr_json_min_get_int(json, "b");

    int result = a * b;

    char payload[64];
    snprintf(payload, sizeof(payload), "{\"result\": %d}", result);

    return abr_synth_execute(ctx, &synth_math_mul_op, payload);
}

/*
 * Register Synthetic Math Operator #2.
 */
void abr_synth_math_mul_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_math_mul_op.operator_id,
        .name = synth_math_mul_op.name,
        .execute = synth_math_mul_exec
    };

    abr_register_operator(ctx, &o);
}

