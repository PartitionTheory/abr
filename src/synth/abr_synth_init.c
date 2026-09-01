#include "abr_context.h"
#include "abr_synth_template_op.h"
#include "abr_synth_json_op.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Initialization Hook.
 *
 * This function is called during ABR system initialization.
 * It registers all synthetic operators.
 */

void abr_synth_init(abr_context_t* ctx)
{
    /* Register Synthetic Operator #1 */
    abr_synth_template_op_register(ctx);

    /* Additional synthetic operators will be added in Step 36+ */
    /* Synthetic Operator #2 */
    abr_synth_json_op_register(ctx);
}

