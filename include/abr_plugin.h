/*
 * abr_plugin.h — ABR v0.5
 *
 * Defines the ABR plugin ABI.
 * Plugins are the transformation units of ABR, operating on either
 * WindowSet or BigIntList depending on plugin type.
 *
 * Phoenix Annotation (scflder):
 *   f = front of plugin entry
 *   s = second / step in ABI selection
 *   l = last stage before VM handoff
 *   c = clock domain exposed through context
 *   d = degree domain (unary expansion)
 *   e = eternal set (persistent invariants)
 *   r = residue domain (post-operation remainder)
 */

#ifndef ABR_PLUGIN_H
#define ABR_PLUGIN_H

#include <stddef.h>
#include <stdint.h>
#include "abr_context.h"

/* Forward declarations */
struct abr_plugin;

/* Plugin type classification */
typedef enum {
    ABR_PLUGIN_WINDOW,
    ABR_PLUGIN_BIGINT,
    ABR_PLUGIN_BRIDGE
} abr_plugin_type;

/* Plugin cost class (for VM scheduling) */
typedef enum {
    ABR_COST_LIGHT,
    ABR_COST_MEDIUM,
    ABR_COST_HEAVY
} abr_cost_class;

/* Plugin ABI */
typedef struct abr_plugin {
    const char* name;
    abr_plugin_type type;
    abr_cost_class cost;

    int is_branching;
    int is_reversible;

    /* Non-branching path */
    void (*process_set)(
        struct abr_plugin* p,
        void* in_set,
        void* flags,
        abr_context_t* ctx
    );

    /* Branching path */
    void (*process_branch)(
        struct abr_plugin* p,
        void* in_set,
        void* flags,
        abr_context_t* ctx,
        size_t* out_count
    );

    /* Optional plugin state */
    void* state;

} abr_plugin;

#endif /* ABR_PLUGIN_H */

