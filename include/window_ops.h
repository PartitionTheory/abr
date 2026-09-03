/*
 * window_ops.h — ABR v0.5
 *
 * Public interface for structural window operations.
 * These functions perform slicing, merging, flipping, stretching, and
 * other transformations used by window-type plugins.
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

#ifndef WINDOW_OPS_H
#define WINDOW_OPS_H

#include "windowset.h"

/* Slice a window into two parts (f → s → l). */
void window_slice(const Window* src, size_t index, Window* left, Window* right);

/* Flip all bits in a window. */
void window_flip(Window* w);

/* Stretch a window by duplicating each bit. */
Window window_stretch(const Window* src);

/* Merge two windows into one. */
Window window_merge(const Window* a, const Window* b);

#endif /* WINDOW_OPS_H */

