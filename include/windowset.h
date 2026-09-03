/*
 * windowset.h — ABR v0.5
 *
 * Defines the Window and WindowSet structures.
 * Window plugins operate on these structural units, performing branching,
 * merging, slicing, flipping, stretching, and other transformations.
 *
 * Phoenix Annotation (scflder):
 *   f = front of window creation
 *   s = second / step in window slicing
 *   l = last stage during destruction
 *   c = clock domain (window operations may increment runtime clock)
 *   d = degree domain (window width relates to unary degree)
 *   e = eternal set (window invariants preserved)
 *   r = residue domain (window remainder after slicing)
 */

#ifndef WINDOWSET_H
#define WINDOWSET_H

#include <stddef.h>
#include <stdint.h>

/* A single window of bits. */
typedef struct {
    size_t length;   /* number of bits */
    size_t width;    /* structural width (d domain) */
    uint8_t* bits;   /* bit array */
} Window;

/* A set of windows. */
typedef struct {
    size_t count;
    Window* windows;
} WindowSet;

#endif /* WINDOWSET_H */

