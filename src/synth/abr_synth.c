#include "abr_context.h"
#include "abr_plugin.h"
#include "abr_operators.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic-operator plugin binding stub.
 *
 * Synthetic operators call plugins through this isolated entry point.
 * This ensures deterministic behavior and compatibility with
 * reversible operator semantics.
 */

abr_plugin_result
abr_synth_plugin(abr_context_t* ctx,
                 const char* class_tag,
                 const char* json)
{
    if (!ctx || !class_tag) {
        return (abr_plugin_result){
            .status = 0,
            .message = "invalid synth context or class_tag",
            .json = "{}"
        };
    }

    /* Synthetic operators always route through the unified operator API. */
    return abr_operator_plugin(ctx, class_tag, json);
}

