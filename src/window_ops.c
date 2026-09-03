/*
 * window_ops.c — ABR v0.5
 *
 * Implements structural window operations:
 * slicing, flipping, stretching, and merging.
 *
 * Phoenix Annotation (scflder):
 *   f = front of operation entry
 *   s = second / step in structural transform
 *   l = last stage before returning result
 *   c = clock domain (operations may increment runtime clock)
 *   d = degree domain (window width relates to unary degree)
 *   e = eternal set (structural invariants preserved)
 *   r = residue domain (remainder window after slicing)
 */

#include "window_ops.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * window_slice
 *
 * Splits a window into two parts at index.
 * This is the 'f → s → l' sequence.
 * ------------------------------------------------------------------------- */
void window_slice(const Window* src, size_t index, Window* left, Window* right)
{
    /* Left window */
    left->length = index;
    left->width  = index;
    left->bits   = malloc(index);
    memcpy(left->bits, src->bits, index);

    /* Right window */
    size_t rlen = src->length - index;
    right->length = rlen;
    right->width  = rlen;
    right->bits   = malloc(rlen);
    memcpy(right->bits, src->bits + index, rlen);
}

/* -------------------------------------------------------------------------
 * window_flip
 *
 * Flips all bits in a window.
 * ------------------------------------------------------------------------- */
void window_flip(Window* w)
{
    for (size_t i = 0; i < w->length; i++)
        w->bits[i] ^= 1;
}

/* -------------------------------------------------------------------------
 * window_stretch
 *
 * Duplicates each bit, doubling window length.
 * ------------------------------------------------------------------------- */
Window window_stretch(const Window* src)
{
    Window w;
    w.length = src->length * 2;
    w.width  = w.length;
    w.bits   = malloc(w.length);

    size_t k = 0;
    for (size_t i = 0; i < src->length; i++) {
        uint8_t b = src->bits[i];
        w.bits[k++] = b;
        w.bits[k++] = b;
    }

    return w;
}

/* -------------------------------------------------------------------------
 * window_merge
 *
 * Concatenates two windows.
 * ------------------------------------------------------------------------- */
Window window_merge(const Window* a, const Window* b)
{
    Window w;
    w.length = a->length + b->length;
    w.width  = w.length;
    w.bits   = malloc(w.length);

    memcpy(w.bits, a->bits, a->length);
    memcpy(w.bits + a->length, b->bits, b->length);

    return w;
}

