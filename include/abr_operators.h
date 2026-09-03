/*
 * abr_operators.h — ABR v0.5
 *
 * Core window operators for ABR.
 * Defines the ABI boundary for slicing, shifting, merging, and degree transforms.
 *
 * Phoenix Annotation (scflder):
 *   f = front of operator entry
 *   s = second / step in operator selection
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_OPERATORS_H
#define ABR_OPERATORS_H

#include <stddef.h>
#include <stdint.h>
#include "windowset.h"

/* -------------------------------------------------------------------------
 * abr_op_shift_left
 *
 * Shift a window left by n bits.
 * ------------------------------------------------------------------------- */
static inline Window abr_op_shift_left(const Window* w, size_t n)
{
    Window out = *w;
    out.offset += n;
    return out;
}

/* -------------------------------------------------------------------------
 * abr_op_shift_right
 *
 * Shift a window right by n bits.
 * ------------------------------------------------------------------------- */
static inline Window abr_op_shift_right(const Window* w, size_t n)
{
    Window out = *w;
    out.offset -= n;
    return out;
}

/* -------------------------------------------------------------------------
 * abr_op_merge
 *
 * Merge two windows into a single WindowSet of size 2.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_op_merge(const Window* a, const Window* b)
{
    WindowSet ws;
    ws.count = 2;
    ws.windows[0] = *a;
    ws.windows[1] = *b;
    return ws;
}

#endif /* ABR_OPERATORS_H */

