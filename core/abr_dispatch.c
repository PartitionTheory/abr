/*
 * abr_dispatch.c — ABR v0.5
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

#include "abr_dispatch.h"
#include "abr_context.h"
#include "abr_synth_vm_trace.h"
#include <string.h>

/* Dispatch extraction: extract a bit window from a byte buffer. */
uint64_t abr_dispatch_extract(
    abr_context* ctx,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!ctx || !src) return 0;

    uint64_t result = abr_core_extract_bits_fn(
        src,
        src_size,
        bit_offset,
        bit_length
    );

    ctx->window  = result; /* f,s,l */
    ctx->residue = 0;      /* r */

    /* Emit trace event. */
    abr_synth_vm_trace_event ev = {
        .plugin_name = "extract",
        .clock       = 0,
        .residue     = ctx->residue
    };
    abr_synth_vm_trace_append(&ctx->trace, &ev);

    return result;
}

/* Dispatch slicing: slice a sub-window from a 64-bit window. */
uint64_t abr_dispatch_slice(
    abr_context* ctx,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!ctx) return 0;

    uint64_t result = abr_core_slice_window_fn(
        window,
        bit_offset,
        bit_length
    );

    ctx->window  = result; /* f,s,l */
    ctx->residue = 0;      /* r */

    /* Emit trace event. */
    abr_synth_vm_trace_event ev = {
        .plugin_name = "slice",
        .clock       = 0,
        .residue     = ctx->residue
    };
    abr_synth_vm_trace_append(&ctx->trace, &ev);

    return result;
}

/* Dispatch plugin execution. */
void abr_dispatch_plugin(
    abr_context* ctx,
    const char* plugin_name
)
{
    if (!ctx || !plugin_name) return;

    /* Emit trace event. */
    abr_synth_vm_trace_event ev = {
        .plugin_name = plugin_name,
        .clock       = 0,
        .residue     = ctx->residue
    };
    abr_synth_vm_trace_append(&ctx->trace, &ev);

    /* Plugin execution is deferred to plugin registry (v0.5 minimal). */
}

