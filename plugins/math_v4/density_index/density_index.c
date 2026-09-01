#include "abr_plugin.h"
#include "abr_synth.h"
#include "abr_core.h"

static const char* plugin_name = "density_index";

abr_plugin_result abr_plugin_execute(const abr_plugin_input* input) {
    abr_plugin_result result = {0};

    // v0.4: Density / index stub
    result.status = 1;
    result.message = "Density Index: structural density and index evaluated.";

    return result;
}

const char* abr_plugin_name() {
    return plugin_name;
}

abr_plugin* abr_plugin_density_index_create() {
    abr_plugin* p = malloc(sizeof(abr_plugin));
    if (!p) return NULL;

    p->name = plugin_name;
    p->execute = abr_plugin_execute;

    return p;
}
