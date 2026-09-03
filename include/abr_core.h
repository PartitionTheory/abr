/*
 * abr_core.h — ABR v0.5
 *
 * Core layer for ABR.
 * This is the ABI boundary between extraction/slicing and execution.
 *
 * Phoenix Annotation (scflder):
 *   f = front of core entry
 *   s = second / step in core transform
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_CORE_H
#define ABR_CORE_H

#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* -------------------------------------------------------------------------
 * abr_core_identity
 *
 * Identity transform for testing and scaffolding.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_core_identity(
    const WindowSet* in,
    abr_context_t* ctx
)
{
    (void)ctx;
    return *in;
}

/* -------------------------------------------------------------------------
 * abr_core_extract
 *
 * Extract raw bytes into a WindowSet.
 * Implemented in core_extract.c.
 * ------------------------------------------------------------------------- */
WindowSet abr_core_extract(const uint8_t* bytes, size_t count);

/* -------------------------------------------------------------------------
 * abr_core_slice
 *
 * Slice a window into a subwindow.
 * Implemented in core_slice.c.
 * ------------------------------------------------------------------------- */
Window abr_core_slice(const Window* src, size_t a, size_t b);

#endif /* ABR_CORE_H */

