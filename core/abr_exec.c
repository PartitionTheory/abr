/*
 * abr_exec.c — ABR v0.5
 *
 * Core execution layer for ABR.
 * Provides the stable execution semantics for:
 *   - extraction
 *   - slicing
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

#include "abr_exec.h"
#include "abr_dispatch.h"
#include "abr_synth_vm_trace.h"
#include <string.h>

/* Execute extraction from a byte buffer into the context window. */
uint64_t abr_exec_extract(
    abr_context* ctx,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!ctx || !src) return 0;

    uint64_t result = abr_dispatch_extract(
        ctx,
        src,
        src_size,
        bit_offset,
        bit_length
    );

    /* Emit trace event. */
    abr_synth_vm_trace_event ev = {
        .plugin_name = "exec_extract",
        .clock       = 0,
        .residue     = ctx->residue
    };
    abr_synth_vm_trace_append(&ctx->trace, &ev);

    return result;
}

/* Execute slicing of a 64-bit window into a sub-window. */
uint64_t abr_exec_slice(
    abr_context* ctx,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!ctx) return 0;

    uint64_t result = abr_dispatch_slice(
        ctx,
        window,
        bit_offset,
        bit_length
    );

    /* Emit trace event. */
    abr_synth_vm_trace_event ev = {
        .plugin_name = "exec_slice",
        .clock       = 0,
        .residue     = ctx->residue
    };
    abr_synth_vm_trace_append(&ctx->trace, &ev);

    return result;
}

/* Execute a plugin by name. */
void abr_exec_plugin(
    abr_context* ctx,
    const char* plugin_name
)
{
    if (!ctx || !plugin_name) return;

    abr_dispatch_plugin(ctx, plugin_name);

    /* Emit trace event. */
    abr_synth_vm_trace_event ev = {
        .plugin_name = plugin_name,
        .clock       = 0,
        .residue     = ctx->residue
    };
    abr_synth_vm_trace_append(&ctx->trace, &ev);
}

