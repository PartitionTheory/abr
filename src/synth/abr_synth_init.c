#include "abr_context.h"
#include "abr_synth_template_op.h"
#include "abr_synth_json_op.h"
#include "abr_synth_set.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Initialization Hook.
 *
 * This function is called during ABR system initialization.
 * It registers all synthetic operators.
 */
void abr_synth_init(abr_context_t* ctx)
{
    /* Add operators to the core synthetic set */
    abr_synth_set_add("synth.core", &synth_template_op);
    abr_synth_set_add("synth.core", &synth_json_op);

    /* Register all operators in the core set */
    abr_synth_set_register_all(ctx, "synth.core");
}

