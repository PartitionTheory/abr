/*
 * core_extract.c — ABR v0.5
 *
 * Converts raw bytes into a WindowSet.
 * This is the entry point of the ABR pipeline.
 *
 * Phoenix Annotation (scflder):
 *   f = front of byte → window extraction
 *   s = second / step in bit expansion
 *   l = last stage before WindowSet assembly
 *   c = clock domain (initial increment)
 *   d = degree domain (window width = unary degree)
 *   e = eternal set (initial invariants)
 *   r = residue domain (unused for extraction)
 */

#include "windowset.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * core_extract
 *
 * Converts a byte array into a single window containing all bits.
 * This is the 'f → s → l' sequence.
 * ------------------------------------------------------------------------- */
WindowSet core_extract(const uint8_t* bytes, size_t count)
{
    WindowSet ws;
    ws.count = 1;
    ws.windows = calloc(1, sizeof(Window));

    Window* w = &ws.windows[0];

    /* f = front: compute bit length */
    w->length = count * 8;
    w->width  = w->length;

    /* s = second: expand bytes → bits */
    w->bits = malloc(w->length);

    size_t k = 0;
    for (size_t i = 0; i < count; i++) {
        uint8_t b = bytes[i];
        for (int bit = 7; bit >= 0; bit--) {
            w->bits[k++] = (b >> bit) & 1;
        }
    }

    /* l = last: WindowSet assembled */
    return ws;
}

