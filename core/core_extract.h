/*
 * core_extract.h — ABR v0.5
 *
 * Core window extraction utilities.
 * Provides safe, bounded extraction of bit windows from streams and buffers.
 *
 * Phoenix Annotation (scflder):
 *   f = front of extraction (start index)
 *   s = second / step through bits
 *   l = last bit of window
 *   d = degree (window width)
 *   r = residue (remaining bits after window)
 */

#ifndef ABR_CORE_EXTRACT_H
#define ABR_CORE_EXTRACT_H

#include <stddef.h>
#include <stdint.h>

/* Extract a window of bits from a byte buffer into a 64-bit value.
 * - src: pointer to source bytes
 * - src_size: number of bytes in src
 * - bit_offset: starting bit index (0 = first bit of src[0])
 * - bit_length: number of bits to extract (<= 64)
 * Returns extracted bits right-aligned in the 64-bit result.
 */
static inline uint64_t abr_core_extract_bits(
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!src || bit_length == 0 || bit_length > 64) {
        return 0;
    }

    size_t end_bit = bit_offset + bit_length;
    size_t total_bits = src_size * 8;

    if (end_bit > total_bits) {
        return 0;
    }

    uint64_t result = 0;
    for (size_t i = 0; i < bit_length; i++) {
        size_t idx = bit_offset + i;
        size_t byte_index = idx / 8;
        size_t bit_index  = 7 - (idx % 8); /* MSB-first */

        uint8_t byte = src[byte_index];
        uint8_t bit  = (byte >> bit_index) & 0x1;

        result = (result << 1) | bit;
    }

    return result;
}

#endif /* ABR_CORE_EXTRACT_H */

