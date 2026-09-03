/*
 * abr_stream.c — ABR v0.5
 *
 * Canonical stream subsystem for ABR.
 *
 * Responsibilities:
 *   - provide streaming window operations
 *   - support sequential window updates
 *   - integrate with runtime context
 *   - support plugin and pipeline execution
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (stream step)
 *   l = last (final window)
 *   d = degree domain (stream length)
 *   r = residue domain (propagated result)
 */

#include "abr_stream.h"
#include "abr_runtime_context.h"

/* Initialize stream */
void abr_stream_init(abr_stream* s, uint64_t initial)
{
    if (!s)
        return;

    s->current = initial;
    s->count   = 0;
}

/* Push a new window value into the stream */
void abr_stream_push(abr_stream* s, uint64_t value)
{
    if (!s)
        return;

    s->current = value;
    s->count++;
}

/* Apply plugin result to stream */
void abr_stream_apply_result(
    abr_stream* s,
    abr_plugin_result result
)
{
    if (!s)
        return;

    s->current = result.window;
    s->count++;
}

/* Extract current window */
uint64_t abr_stream_current(const abr_stream* s)
{
    return s ? s->current : 0;
}

/* Extract stream length */
size_t abr_stream_length(const abr_stream* s)
{
    return s ? s->count : 0;
}

