/*
 * core_slice.c — ABR v0.5
 *
 * Implements slicing operations for Window objects.
 * This is the low-level utility used by window plugins and the
 * extraction pipeline.
 *
 * Phoenix Annotation (scflder):
 *   f = front of slice entry
 *   s = second / step in bit copy
 *   l = last stage before subwindow assembly
 *   c = clock domain (slice may increment runtime clock)
 *   d = degree domain (subwindow width relates to unary degree)
 *   e = eternal set (structural invariants preserved)
 *   r = residue domain (unused for slicing)
 */

#include "windowset.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * core_slice
 *
 * Extracts a subwindow from src[a..b).
 * This is the 'f → s → l' sequence.
 * ------------------------------------------------------------------------- */
Window core_slice(const Window* src, size_t a, size_t b)
{
    Window w;

    /* f = front: compute new length */
    w.length = b - a;
    w.width  = w.length;

    /* s = second: allocate and copy bits */
    w.bits = malloc(w.length);
    memcpy(w.bits, src->bits + a, w.length);

    /* l = last: subwindow assembled */
    return w;
}

