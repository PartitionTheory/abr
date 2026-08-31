#ifndef ABR_REVERSE_H
#define ABR_REVERSE_H

/*
 * ABR‑Rebirth: Reversible Semantics Layer (Phase 4 Step 02)
 * ---------------------------------------------------------
 * This module defines the API for reversible execution.
 * It does not change Phase 1–3 behavior; it adds new
 * capabilities on top of the existing architecture.
 */

#include "abr_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Run an operator forward, capturing state for possible reversal. */
int abr_reverse_forward(abr_context_t *ctx, int operator_id, void *args);

/* Run the previously captured operator in reverse. */
int abr_reverse_backward(abr_context_t *ctx, int operator_id, void *args);

#ifdef __cplusplus
}
#endif

#endif /* ABR_REVERSE_H */

