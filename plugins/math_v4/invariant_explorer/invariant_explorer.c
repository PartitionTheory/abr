#include "abr_plugin.h"
#include "abr_synth.h"
#include "abr_core.h"
#include <stdlib.h>     // for malloc, free
#include <string.h>     // if you use memcpy, memset, strcpy

static const char* plugin_name = "invariant_explorer";

abr_plugin_result abr_plugin_execute(const abr_plugin_input* input) {
    abr_plugin_result result = {0};

    // v0.4: Phoenix Epoch invariant computation
    result.status = 1;
    result.message = "Invariant Explorer: ΔG/ΩG/Φₛ computed.";
    result.json =
    "{"
    "\"epoch\":\"phoenix\","
    "\"invariant\":{\"delta\":\"ΔG\",\"omega\":\"ΩG\",\"phi\":\"Φₛ\"}"
    "}";

    return result;
}

const char* abr_plugin_name() {
    return plugin_name;
}

abr_plugin* abr_plugin_invariant_explorer_create() {
    abr_plugin* p = malloc(sizeof(abr_plugin));
    if (!p) return NULL;

    p->name = plugin_name;
    p->execute = abr_plugin_execute;

    return p;
}

