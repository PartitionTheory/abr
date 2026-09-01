#include "abr_context.h"
#include "abr_synth_template_op.h"
#include "abr_synth_json_op.h"
#include "abr_synth_set.h"
#include "abr_synth_activate_op.h"
#include "abr_synth_math_add_op.h"
#include "abr_synth_math_mul_op.h"
#include "abr_synth_math_pow_op.h"
#include "abr_synth_math_basic_set.h"
#include "abr_synth_math_activate_op.h"
#include "abr_synth_math_deactivate_op.h"
#include "abr_synth_math_status_op.h"
#include "abr_synth_set_list_op.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Initialization Hook.
 *
 * This function is called during ABR system initialization.
 * It registers all synthetic operators.
 */
void abr_synth_init(abr_context_t* ctx)
{
    /* Core synthetic operators */
    abr_synth_set_add("synth.core", &synth_template_op);
    abr_synth_set_add("synth.core", &synth_json_op);

    /* Math synthetic operators */
    abr_synth_set_add("synth.math", &synth_math_add_op);
    abr_synth_set_add("synth.math", &synth_math_mul_op);
    abr_synth_set_add("synth.math", &synth_math_pow_op);

    /* Register core operators */
    abr_synth_set_register_all(ctx, "synth.core");

    /* Register math operators */
    abr_synth_set_register_all(ctx, "synth.math");

    /* Initialize math families */
    abr_synth_math_basic_set_init();

    /* Register math activation operator */
    abr_synth_math_activate_op_register(ctx);

    /* Register math deactivation operator */
    abr_synth_math_deactivate_op_register(ctx);

    /* Register math status operator */
    abr_synth_math_status_op_register(ctx);

    /* Register operator-set enumeration */
    abr_synth_set_list_op_register(ctx);

    /* Register set-activation operator */
    abr_synth_activate_op_register(ctx);
}

