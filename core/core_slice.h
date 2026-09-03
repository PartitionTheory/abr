/*
 * core_slice.h — ABR v0.5
 *
 * Core window slicing utilities.
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

#ifndef ABR_CORE_SLICE_H
#define ABR_CORE_SLICE_H

#include <stddef.h>
#include <stdint.h>

/* Slice a 64‑bit window into a smaller right‑aligned sub‑window.
 * - window: 64‑bit input window
 * - bit_offset: starting bit index (0 = MSB of window)
 * - bit_length: number of bits to slice (<= 64)
 * Returns the sliced bits right‑aligned.
 */
static inline uint64_t abr_core_slice_window(
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
)
{
    if (bit_length == 0 || bit_length > 64) {
        return 0;
    }

    size_t end_bit = bit_offset + bit_length;
    if (end_bit > 64) {
        return 0;
    }

    uint64_t shifted = window >> (64 - end_bit);
    uint64_t mask = (bit_length == 64) ? UINT64_MAX : ((1ULL << bit_length) - 1);

    return shifted & mask;
}

#endif /* ABR_CORE_SLICE_H */

