/*
 * abr_reverse.h — ABR v0.5
 *
 * Minimal reversible operators for ABR.
 * Provides reversible window and windowset transforms.
 *
 * Phoenix Annotation (scflder):
 *   f = front of reverse entry
 *   s = second / step in reverse selection
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_REVERSE_H
#define ABR_REVERSE_H

#include <stddef.h>
#include <stdint.h>
#include "windowset.h"

/* -------------------------------------------------------------------------
 * abr_reverse_window
 *
 * Reverse the bits of a single Window.
 * ------------------------------------------------------------------------- */
static inline Window abr_reverse_window(const Window* w)
{
    Window out = *w;
    for (size_t i = 0; i < w->length / 2; i++) {
        uint8_t tmp = out.bits[i];
        out.bits[i] = out.bits[w->length - 1 - i];
        out.bits[w->length - 1 - i] = tmp;
    }
    return out;
}

/* -------------------------------------------------------------------------
 * abr_reverse_set
 *
 * Reverse the order of windows in a WindowSet.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_reverse_set(const WindowSet* ws)
{
    WindowSet out = *ws;
    for (size_t i = 0; i < ws->count / 2; i++) {
        Window tmp = out.windows[i];
        out.windows[i] = out.windows[ws->count - 1 - i];
        out.windows[ws->count - 1 - i] = tmp;
    }
    return out;
}

#endif /* ABR_REVERSE_H */

