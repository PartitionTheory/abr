#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator #1 — canonical template operator.
 *
 * This operator is the first real synthetic operator.
 * It verifies the synthetic operator pipeline:
 *   - registration
 *   - dispatch
 *   - execution
 *   - plugin invocation
 */

static abr_synth_operator_t synth_template_op = {
    .operator_id = 1000,
    .name = "synth.template",
    .class_tag = "synth.template"
};

/*
 * Register Synthetic Operator #1.
 * Called during system initialization.
 */
void abr_synth_template_op_register(abr_context_t* ctx)
{
    abr_synth_operator_register(ctx, &synth_template_op);
}

