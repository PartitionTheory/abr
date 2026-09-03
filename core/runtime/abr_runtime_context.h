/*
 * abr_runtime_context.h — ABR v0.5
 *
 * Canonical runtime context for ABR.
 *
 * Responsibilities:
 *   - hold current window and residue
 *   - hold plugin execution state
 *   - hold runtime flags and error info
 *   - provide ABI-stable context for all plugins
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (intermediate step)
 *   l = last (final window)
 *   d = degree domain (window width)
 *   r = residue domain (propagated result)
 */

#ifndef ABR_RUNTIME_CONTEXT_H
#define ABR_RUNTIME_CONTEXT_H

#include <stdint.h>

/* Runtime context */
typedef struct abr_context
{
    /* Core window state */
    uint64_t window;
    uint64_t residue;

    /* Execution metadata */
    const char* plugin_name;
    int status_code;

    /* Error handling */
    const char* error_message;

    /* Flags */
    uint32_t flags;

} abr_context;

#endif /* ABR_RUNTIME_CONTEXT_H */

