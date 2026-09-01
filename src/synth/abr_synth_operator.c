#include "abr_context.h"
#include "abr_operators.h"
#include "abr_synth.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Definition + Registration Stub
 *
 * This file defines the structural template for synthetic operators.
 * Actual synthetic operators will be added in Step 34 and onward.
 */

typedef struct abr_synth_operator {
    int operator_id;
    const char* name;
    const char* class_tag;   /* plugin class tag */
} abr_synth_operator_t;

/*
 * Synthetic operator execution stub.
 * All synthetic operators route through abr_synth_plugin().
 */
static int
abr_synth_operator_execute(abr_context_t* ctx,
                           abr_synth_operator_t* op,
                           void* args)
{
    if (!ctx || !op) {
        return -1;
    }

    /* Synthetic operators always call plugins by class. */
    abr_plugin_result r =
        abr_synth_plugin(ctx, op->class_tag, (const char*)args);

    return r.status;
}

/*
 * Synthetic operator registration stub.
 * Step 34 will populate real operators here.
 */
void
abr_synth_operator_register(abr_context_t* ctx,
                            abr_synth_operator_t* op)
{
    /* Register synthetic operator into the operator subsystem. */
    abr_operator_t o = {
        .operator_id = op->operator_id,
        .name = op->name,
        .execute = (int (*)(abr_context_t*, void*))abr_synth_operator_execute
    };

    abr_register_operator(ctx, &o);
}

