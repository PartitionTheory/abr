/*
 * abr_dispatch.h — ABR v0.5
 *
 * Core dispatch layer for ABR.
 * Routes execution requests from the core engine to:
 *   - window extraction
 *   - window slicing
 *   - plugin invocation
 *   - synthetic VM trace emission
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (step through execution)
 *   l = last (terminal window)
 *   d = degree domain (window width)
 *   r = residue domain (last result)
 */

#ifndef ABR_DISPATCH_H
#define ABR_DISPATCH_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"
#include "core_extract.h"
#include "core_slice.h"

/* Dispatch extraction: extract a bit window from a byte buffer. */
uint64_t abr_dispatch_extract(
    abr_context* ctx,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
);

/* Dispatch slicing: slice a sub-window from a 64-bit window. */
uint64_t abr_dispatch_slice(
    abr_context* ctx,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
);

/* Dispatch plugin execution (branching or non-branching). */
void abr_dispatch_plugin(
    abr_context* ctx,
    const char* plugin_name
);

#endif /* ABR_DISPATCH_H */

