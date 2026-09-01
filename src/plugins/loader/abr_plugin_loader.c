#include "abr_plugin_loader.h"
#include "abr_plugin_registry.h"
#include "abr_plugin.h"
#include <stdlib.h>

abr_plugin** abr_plugin_load_all(size_t* count) {
    const abr_plugin_descriptor* table = abr_plugin_registry(count);
    if (*count == 0) return NULL;

    abr_plugin** list = malloc(sizeof(abr_plugin*) * (*count));
    if (!list) return NULL;

    for (size_t i = 0; i < *count; i++) {
        list[i] = table[i].create();
        if (!list[i]) {
            // loader failure: clean up
            for (size_t j = 0; j < i; j++) {
                free(list[j]);
            }
            free(list);
            return NULL;
        }
    }

    return list;
}

void abr_plugin_free_all(abr_plugin** list, size_t count) {
    if (!list) return;

    for (size_t i = 0; i < count; i++) {
        free(list[i]);
    }

    free(list);
}

