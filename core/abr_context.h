/*
 * abr_context.h — ABR v0.5
 *
 * Core execution context for ABR.
 * Holds window state, residue state, plugin registry pointer,
 * and synthetic VM trace accumulator.
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (step through execution)
 *   l = last (terminal window)
 *   d = degree domain (window width)
 *   r = residue domain (last result)
 */

#ifndef ABR_CONTEXT_H
#define ABR_CONTEXT_H

#include <stdint.h>
#include <stddef.h>
#include "abr_synth_vm_trace.h"

/* ABR execution context (v0.5 canonical). */
typedef struct abr_context {
    uint64_t window;          /* current 64‑bit window (f,s,l) */
    uint64_t residue;         /* residue domain (r) */
    size_t   width;           /* window width (d) */

    /* Synthetic VM trace accumulator. */
    abr_synth_vm_trace trace;

    /* Plugin registry pointer (opaque). */
    void* plugin_registry;
} abr_context;

/* Initialize context with a window and width. */
void abr_context_init(
    abr_context* ctx,
    uint64_t window,
    size_t width
);

/* Reset context residue and trace. */
void abr_context_reset(abr_context* ctx);

#endif /* ABR_CONTEXT_H */

