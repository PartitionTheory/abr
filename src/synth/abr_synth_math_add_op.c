#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Math Operator #1 — Addition.
 *
 * This operator accepts a JSON payload:
 *   { "a": <int>, "b": <int> }
 * and passes it to the plugin system for synthetic addition.
 */

static abr_synth_operator_t synth_math_add_op = {
    .operator_id = 2001,
    .name = "synth.math.add",
    .class_tag = "synth.math.add"
};

/*
 * Unified execution wrapper (Step 39).
 */
static int synth_math_add_exec(abr_context_t* ctx, void* args)
{
    return abr_synth_execute(ctx, &synth_math_add_op, args);
}

/*
 * Register Synthetic Math Operator #1.
 */
void abr_synth_math_add_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_math_add_op.operator_id,
        .name = synth_math_add_op.name,
        .execute = synth_math_add_exec
    };

    abr_register_operator(ctx, &o);
}

