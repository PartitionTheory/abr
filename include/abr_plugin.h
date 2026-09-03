/*
 * abr_plugin.h — ABR v0.5
 *
 * Unified plugin ABI for all plugin families:
 * - Window plugins
 * - BigInt plugins
 * - Bridge plugins
 * - Future VM plugins
 *
 * Phoenix Annotation (scflder):
 *   f = front of plugin creation
 *   s = second / step in plugin execution
 *   l = last stage during destruction
 *   c = clock domain (plugin may mutate context clock)
 *   d = degree domain (plugin may mutate unary degree)
 *   e = eternal set (plugin may preserve invariants)
 *   r = residue domain (plugin may store last result)
 */

#ifndef ABR_PLUGIN_H
#define ABR_PLUGIN_H

#include "abr_context.h"
#include "abr_flags.h"
#include "windowset.h"

/* Plugin type */
typedef enum {
    ABR_PLUGIN_WINDOW,
    ABR_PLUGIN_BIGINT,
    ABR_PLUGIN_BRIDGE
} abr_plugin_type;

/* Unified plugin metadata */
typedef struct abr_plugin {
    const char* name;
    const char* version;
    const char* description;

    abr_plugin_type type;

    /* Universal flags */
    abr_flags_t flags;

    /* Window plugin entry point */
    WindowSet (*process_set)(
        const WindowSet* in,
        const abr_flags_t* fl,
        abr_context_t* ctx
    );

    /* Branching window plugin entry point */
    WindowSet* (*process_branch)(
        const WindowSet* in,
        const abr_flags_t* fl,
        abr_context_t* ctx,
        size_t* out_count
    );

    /* BigInt plugin entry point (future) */
    void* (*process_list)(
        const void* in,
        const abr_flags_t* fl,
        abr_context_t* ctx
    );

} abr_plugin;

#endif /* ABR_PLUGIN_H */

