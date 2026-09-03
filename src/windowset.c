/*
 * windowset.c — ABR v0.5
 *
 * Implements basic Window and WindowSet operations.
 *
 * Phoenix Annotation (scflder):
 *   f = front of window creation
 *   s = second / step in window cloning
 *   l = last stage during destruction
 *   c = clock domain (window operations may increment runtime clock)
 *   d = degree domain (window width relates to unary degree)
 *   e = eternal set (window invariants preserved)
 *   r = residue domain (window remainder after slicing)
 */

#include "windowset.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * window_create
 *
 * Allocates a new window with given length.
 * This is the 'f' (front) of window lifecycle.
 * ------------------------------------------------------------------------- */
Window window_create(size_t length)
{
    Window w;
    w.length = length;
    w.width  = length;
    w.bits   = calloc(length, sizeof(uint8_t));
    return w;
}

/* -------------------------------------------------------------------------
 * window_clone
 *
 * Clones a window.
 * This is the 's' (second) stage of window lifecycle.
 * ------------------------------------------------------------------------- */
Window window_clone(const Window* src)
{
    Window w;
    w.length = src->length;
    w.width  = src->width;
    w.bits   = malloc(src->length);
    memcpy(w.bits, src->bits, src->length);
    return w;
}

/* -------------------------------------------------------------------------
 * window_destroy
 *
 * Frees a window.
 * This is the 'l' (last) stage of window lifecycle.
 * ------------------------------------------------------------------------- */
void window_destroy(Window* w)
{
    if (!w || !w->bits)
        return;
    free(w->bits);
    w->bits = NULL;
}

/* -------------------------------------------------------------------------
 * windowset_destroy
 *
 * Frees a WindowSet.
 * ------------------------------------------------------------------------- */
void windowset_destroy(WindowSet* ws)
{
    if (!ws)
        return;

    for (size_t i = 0; i < ws->count; i++)
        window_destroy(&ws->windows[i]);

    free(ws->windows);
    ws->windows = NULL;
}

