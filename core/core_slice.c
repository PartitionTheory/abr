/*
 * core_slice.c — ABR v0.5
 *
 * Implementation of core window slicing utilities.
 * Provides safe slicing of bit‑windows into sub‑windows, enabling
 * operator‑level decomposition and VM‑level window partitioning.
 *
 * Phoenix Annotation (scflder):
 *   f = front of slice (start of sub‑window)
 *   s = second / step through slice bits
 *   l = last bit of slice
 *   d = degree (slice width)
 *   r = residue (remaining bits after slice)
 */

#include "core_slice.h"
#include <stddef.h>
#include <stdint.h>

/* Stable ABI symbol for linking.
 * Forwards to the inline implementation in core_slice.h.
 */
uint64_t abr_core_slice_window_fn(
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
)
{
    return abr_core_slice_window(window, bit_offset, bit_length);
}

