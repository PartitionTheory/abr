/*
 * abr_math_v4_common.h — ABR v0.5
 *
 * Shared definitions used by all math_v4 plugins.
 */

#ifndef ABR_MATH_V4_COMMON_H
#define ABR_MATH_V4_COMMON_H
#include "abr.h"
#include "abr_plugin.h"
#include "abr_math_v4_common.h"

#include <stdint.h>

/* Shared structure for math_v4 plugin internal state */
struct abr_math_v4_state {
    uint64_t seed;
    uint64_t depth;
};

/* Utility: clamp a value to a range */
static inline uint64_t abr_math_v4_clamp(uint64_t x, uint64_t lo, uint64_t hi)
{
    return (x < lo) ? lo : (x > hi) ? hi : x;
}

/* Utility: simple mixing function */
static inline uint64_t abr_math_v4_mix(uint64_t a, uint64_t b)
{
    return (a ^ (b << 1)) + (b ^ (a >> 1));
}

#endif /* ABR_MATH_V4_COMMON_H */

