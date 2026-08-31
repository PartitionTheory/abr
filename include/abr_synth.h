#include "abr_interface.h"
#include "abr_stream.h"

#ifndef ABR_SYNTH_H
#define ABR_SYNTH_H

/*
 * ABR‑Rebirth: Synthetic Math Layer (Phase 4 Step 03)
 * ---------------------------------------------------
 * This module defines the API for Phoenix Epoch synthetic
 * mathematics: structural operators, reversible algebra,
 * and gradient‑bounded transformations.
 *
 * Phase 4 introduces synthetic operators that operate on
 * ABR streams, contexts, and reversible state. These are
 * the first Phoenix‑aligned mathematical constructs in the
 * ABR‑Rebirth architecture.
 */


#ifdef __cplusplus
extern "C" {
#endif

/* Apply a synthetic operator to a stream. */
int abr_synth_apply(abr_context_t *ctx, abr_stream_t *stream, int operator_id);

/* Apply a reversible synthetic transformation. */
int abr_synth_reverse(abr_context_t *ctx, abr_stream_t *stream, int operator_id);

/* Validate synthetic operator coherence constraints. */
int abr_synth_check_coherence(abr_context_t *ctx, int operator_id);

#ifdef __cplusplus
}
#endif

#endif /* ABR_SYNTH_H */

