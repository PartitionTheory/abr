#ifndef ABR_PLUGIN_REGISTRY_H
#define ABR_PLUGIN_REGISTRY_H

#include "abr_plugin.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct abr_plugin_descriptor {
    const char* name;
    abr_plugin* (*create_fn)(void);
} abr_plugin_descriptor;

/* Return the static plugin table */
const abr_plugin_descriptor* abr_plugin_registry(size_t* count);

/* Lookup helpers */
abr_plugin* abr_plugin_registry_find_by_name(const char* name);
abr_plugin* abr_plugin_registry_find_by_class(const char* class_tag);

#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_REGISTRY_H */

