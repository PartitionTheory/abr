/*
 * core_extract.c — ABR v0.5
 *
 * Implementation of core window extraction utilities.
 * Provides safe, bounded extraction of bit windows from streams and buffers.
 *
 * Phoenix Annotation (scflder):
 *   f = front of extraction (start index)
 *   s = second / step through bits
 *   l = last bit of window
 *   d = degree (window width)
 *   r = residue (remaining bits after window)
 */

#include "core_extract.h"
#include <stddef.h>
#include <stdint.h>

/* Extract a window of bits from a byte buffer into a 64-bit value.
 * This function simply forwards to the inline implementation in the header.
 * It exists to provide a stable symbol for linking and ABI consistency.
 */
uint64_t abr_core_extract_bits_fn(
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
)
{
    return abr_core_extract_bits(src, src_size, bit_offset, bit_length);
}

