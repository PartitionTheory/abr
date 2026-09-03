/*
 * abr_stream.h — ABR v0.5
 *
 * Stream ingestion layer for ABR.
 * Defines the ABI boundary between raw byte input and WindowSet extraction.
 *
 * Phoenix Annotation (scflder):
 *   f = front of stream entry
 *   s = second / step in byte ingestion
 *   l = last stage before extraction
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may be inferred)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_STREAM_H
#define ABR_STREAM_H

#include <stddef.h>
#include <stdint.h>
#include "windowset.h"
#include "abr_context.h"

/* -------------------------------------------------------------------------
 * abr_stream_load
 *
 * Load raw bytes from a buffer into a WindowSet via abr_core_extract.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_stream_load(
    const uint8_t* bytes,
    size_t count,
    abr_context_t* ctx
)
{
    return abr_core_extract(bytes, count);
}

#endif /* ABR_STREAM_H */

