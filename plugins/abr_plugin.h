/*
 * abr_plugin.h — ABR v0.5
 *
 * Canonical plugin ABI for ABR.
 * Defines:
 *   - plugin creation
 *   - plugin execution
 *   - plugin destruction
 *   - plugin metadata
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (step through plugin)
 *   l = last (plugin output)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#ifndef ABR_PLUGIN_H
#define ABR_PLUGIN_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"

/* Plugin result type. */
typedef struct abr_plugin_result {
    uint64_t window;   /* updated window */
    uint64_t residue;  /* updated residue */
} abr_plugin_result;

/* Plugin object. */
typedef struct abr_plugin {
    const char* name;

    /* Create plugin instance. */
    void (*create)(struct abr_plugin* self);

    /* Execute plugin. */
    abr_plugin_result (*execute)(
        struct abr_plugin* self,
        abr_context* ctx
    );

    /* Destroy plugin instance. */
    void (*destroy)(struct abr_plugin* self);
} abr_plugin;

/* Plugin factory signature. */
typedef abr_plugin* (*abr_plugin_factory)(void);

#endif /* ABR_PLUGIN_H */

