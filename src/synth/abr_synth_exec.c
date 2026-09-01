#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include <string.h>

/*
 * Phoenix v0.4-greenbuild:
 * Unified Synthetic Operator Execution Pipeline.
 *
 * All synthetic operators must execute through this function.
 */

int abr_synth_execute(abr_context_t* ctx,
                      abr_synth_operator_t* op,
                      void* args)
{
    if (!ctx || !op) {
        return -1;
    }

    const char* payload = (const char*)args;

    /* All synthetic operators dispatch by class tag */
    abr_plugin_result r =
        abr_synth_plugin(ctx, op->class_tag, payload);

    return r.status;
}

