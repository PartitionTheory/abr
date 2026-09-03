/*
 * abr_plugin_registry.h — ABR v0.5
 *
 * Public interface for the ABR plugin registry.
 * The registry stores all plugins compiled into the system and provides
 * lookup functions for the dispatch layer and VM.
 *
 * Phoenix Annotation (scflder):
 *   f = front of registry initialization
 *   s = second / step in plugin registration
 *   l = last stage during shutdown
 *   c = clock domain (plugin timing metadata)
 *   d = degree domain (plugin unary metadata)
 *   e = eternal set (plugin invariants)
 *   r = residue domain (last lookup result)
 */

#ifndef ABR_PLUGIN_REGISTRY_H
#define ABR_PLUGIN_REGISTRY_H

#include "abr_plugin.h"
#include "abr_context.h"

/* Initialize the plugin registry (f). */
int abr_plugin_registry_init(abr_context_t* ctx);

/* Shut down the plugin registry (l). */
void abr_plugin_registry_shutdown(abr_context_t* ctx);

/* Lookup a plugin by name (s → r). */
abr_plugin_t* abr_plugin_registry_get(const char* name);

#endif /* ABR_PLUGIN_REGISTRY_H */

