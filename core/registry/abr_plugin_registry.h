/*
 * abr_plugin_registry.h — ABR v0.5
 *
 * Unified plugin registry interface.
 */

#ifndef ABR_PLUGIN_REGISTRY_H
#define ABR_PLUGIN_REGISTRY_H

#include "abr_plugin.h"

typedef abr_plugin* (*abr_plugin_factory)(void);

void   abr_plugin_registry_init(void);
void   abr_plugin_registry_register(abr_plugin_factory factory);
size_t abr_plugin_registry_count(void);

abr_plugin* abr_plugin_registry_create(size_t index);
abr_plugin* abr_plugin_registry_create_by_name(const char* name);

#endif /* ABR_PLUGIN_REGISTRY_H */

