/*
 * abr_core.h — ABR v0.5
 *
 * Central core engine for ABR.
 * Provides the stable ABI for:
 *   - initializing the core engine
 *   - executing extraction and slicing
 *   - invoking plugins
 *   - producing synthetic VM traces
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (step through execution)
 *   l = last (terminal window)
 *   d = degree domain (window width)
 *   r = residue domain (last result)
 */

#ifndef ABR_CORE_H
#define ABR_CORE_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"
#include "abr_vm.h"

/* Core engine object (v0.5 minimal). */
typedef struct abr_core {
    abr_vm vm;   /* embedded VM */
} abr_core;

/* Initialize core engine with initial window and width. */
void abr_core_init(
    abr_core* core,
    uint64_t window,
    size_t width
);

/* Execute extraction through core engine. */
uint64_t abr_core_extract(
    abr_core* core,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
);

/* Execute slicing through core engine. */
uint64_t abr_core_slice(
    abr_core* core,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
);

/* Execute plugin through core engine. */
void abr_core_plugin(
    abr_core* core,
    const char* plugin_name
);

#endif /* ABR_CORE_H */

