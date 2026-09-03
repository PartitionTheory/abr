#ifndef ABR_DISPATCH_H
#define ABR_DISPATCH_H

/*
 * ABR‑Rebirth: Operator Dispatch Layer (Phase 4 Step 05)
 * ------------------------------------------------------
 * Routes operator execution requests through the correct subsystem:
 * core, synthetic math, reversible semantics, or plugin operators.
 */

#include "abr_context.h"
#include "abr_plugin.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dispatch an operator by ID through the correct subsystem. */
abr_plugin_result
abr_dispatch_plugin_by_class(abr_context_t *ctx,
                             const char *class_tag,
                             const char *json);

#ifdef __cplusplus
}
#endif

#endif /* ABR_DISPATCH_H */

