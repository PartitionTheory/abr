#include "abr_context.h"
#include "abr_synth_template_op.h"
#include "abr_synth_json_op.h"
#include "abr_synth_set.h"
#include "abr_synth_activate_op.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Initialization Hook.
 *
 * This function is called during ABR system initialization.
 * It registers all synthetic operators.
 */
void abr_synth_init(abr_context_t* ctx)
{
    abr_synth_set_add("synth.core", &synth_template_op);
    abr_synth_set_add("synth.core", &synth_json_op);

    /* Register core operators */
    abr_synth_set_register_all(ctx, "synth.core");

    /* Register the set-activation operator */
    abr_synth_activate_op_register(ctx);
}


