/*
 * ABR‑Rebirth: Operator Dispatch Layer (Phase 4 Step 05)
 * ------------------------------------------------------
 * This module defines the dispatch API that routes operator
 * execution requests through the correct subsystem: core,
 * synthetic math, reversible semantics, or plugin operators.
 */

#include "abr_interface.h"
#include "abr_exec.h"
#include "abr_reverse.h"
#include "abr_synth.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dispatch an operator by ID through the correct subsystem. */
int abr_dispatch(abr_context_t *ctx, int operator_id, void *args);

#ifdef __cplusplus
}
#endif

#endif /* ABR_DISPATCH_H */
