#include "abr_exec.h"
#include "abr_context.h"
#include "abr_interface.h"
#include "abr_plugin.h"
/*
 * ABR-Rebirth: Execution Layer (Phoenix v0.4-greenbuild)
 *
 * The execution layer mediates between operator implementations
 * and the VM/interface subsystems. It is intentionally thin.
 */

int abr_exec_operator(abr_context_t* ctx, int operator_id, void* args)
{
    return abr_interface_execute(ctx, operator_id, args);
}

/*
 * Phoenix v0.4-greenbuild:
 * Execution-layer class-based plugin invocation.
 *
 * This allows operator implementations to call plugins during execution.
 */
abr_plugin_result
abr_exec_call_plugin_by_class(abr_context_t* ctx,
                              const char* class_tag,
                              const char* json)
{
    if (!ctx || !class_tag) {
        return (abr_plugin_result){
            .status = 0,
            .message = "invalid exec context or class_tag",
            .json = "{}"
        };
    }

    return abr_interface_exec_plugin_by_class(ctx, class_tag, json);
}
