/*
 * abr_exec.h — ABR v0.5
 *
 * Core execution layer for ABR.
 * Defines the stable ABI for executing:
 *   - extraction operations
 *   - slicing operations
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

#ifndef ABR_EXEC_H
#define ABR_EXEC_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"

/* Execute extraction from a byte buffer into the context window. */
uint64_t abr_exec_extract(
    abr_context* ctx,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
);

/* Execute slicing of a 64-bit window into a sub-window. */
uint64_t abr_exec_slice(
    abr_context* ctx,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
);

/* Execute a plugin by name. */
void abr_exec_plugin(
    abr_context* ctx,
    const char* plugin_name
);

#endif /* ABR_EXEC_H */

