#ifndef ABR_OPERATOR_H
#define ABR_OPERATOR_H

#include "abr_context.h"

/*
 * ABR-Rebirth: Operator Subsystem (Phoenix v0.4-greenbuild)
 *
 * This header defines the operator-level API used by internal
 * operators, synthetic operators, and reversible semantics.
 */

typedef struct abr_operator {
    int operator_id;
    const char* name;
    int (*execute)(abr_context_t* ctx, void* args);
} abr_operator_t;

#ifndef ABR_OPERATOR_PLUGIN_CLASS_EXEC_H
#define ABR_OPERATOR_PLUGIN_CLASS_EXEC_H

#include "abr_plugin.h"
#include "abr_interface.h"

/*
 * Phoenix v0.4-greenbuild:
 * Operator-level class-based plugin invocation.
 *
 * Operators may call plugins directly through the interface layer.
 */
static inline abr_plugin_result
abr_operator_call_plugin_by_class(abr_context_t* ctx,
                                  const char* class_tag,
                                  const char* json)
{
    return abr_interface_exec_plugin_by_class(ctx, class_tag, json);
}

#endif


#endif

