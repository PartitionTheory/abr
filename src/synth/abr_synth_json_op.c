#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator #2 — JSON-payload operator.
 *
 * This operator accepts a JSON string as its argument and passes it
 * directly to the plugin system via abr_synth_plugin().
 */

static abr_synth_operator_t synth_json_op = {
    .operator_id = 1001,
    .name = "synth.json",
    .class_tag = "synth.json"
};

/*
 * Register Synthetic Operator #2.
 * Called during synthetic subsystem initialization.
 */
static int synth_json_exec(abr_context_t* ctx, void* args)
{
    return abr_synth_execute(ctx, &synth_json_op, args);
}

void abr_synth_json_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_json_op.operator_id,
        .name = synth_json_op.name,
        .execute = synth_json_exec
    };

    abr_register_operator(ctx, &o);
}

