/*
 * abr_cli.c — ABR v0.5
 *
 * Canonical CLI entrypoint for Arbitrary Bit Read.
 *
 * Uses:
 *   - abr_plugin_registry_create_by_name()
 *   - abr_plugin_create_fn (void)
 *   - abr_plugin_execute_fn (returns abr_plugin_result)
 *   - abr_plugin_destroy_fn (void)
 *   - abr_context (window, residue, plugin_name, status_code, error_message, flags)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "abr.h"

#include "abr_plugin_loader_math_v4.h"
#include "abr_plugin_loader_builtin.h"
#include "abr_plugin_registry.h"

int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr,
            "usage: %s --plugin <name> --window <uint64>\n",
            argv[0]
        );
        return 1;
    }

    const char* plugin_name = NULL;
    const char* window_str  = NULL;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--plugin") && i + 1 < argc) {
            plugin_name = argv[++i];
        } else if (!strcmp(argv[i], "--window") && i + 1 < argc) {
            window_str = argv[++i];
        }
    }

    if (!plugin_name || !window_str) {
        fprintf(stderr, "error: missing --plugin or --window\n");
        return 1;
    }

    uint64_t window = strtoull(window_str, NULL, 0);

    /* Initialize registry and load all plugins */
    abr_plugin_registry_init();
    abr_plugin_loader_builtin_register_all();
    abr_plugin_loader_math_v4_register_all();

    /* Create plugin instance from registry */
    abr_plugin* plugin = abr_plugin_registry_create_by_name(plugin_name);
    if (!plugin) {
        fprintf(stderr, "error: plugin '%s' not found\n", plugin_name);
        return 1;
    }

    /* Initialize plugin (void create) */
    if (plugin->create) {
        plugin->create(plugin);
    }

    /* Prepare runtime context */
    abr_context ctx = {0};
    ctx.window      = window;
    ctx.residue     = 0;
    ctx.plugin_name = plugin_name;
    ctx.status_code = 0;
    ctx.error_message = NULL;
    ctx.flags       = 0;

    /* Execute plugin */
    abr_plugin_result result = {0};
    if (plugin->execute) {
        result = plugin->execute(plugin, &ctx);
    } else {
        fprintf(stderr, "error: plugin '%s' has no execute() function\n", plugin_name);
        if (plugin->destroy) {
            plugin->destroy(plugin);
        }
        return 1;
    }

    /* Destroy plugin instance */
    if (plugin->destroy) {
        plugin->destroy(plugin);
    }

    /* Print result in ABI terms */
    printf("plugin:  %s\n", plugin_name);
    printf("window:  %llu\n", (unsigned long long)result.window);
    printf("residue: %llu\n", (unsigned long long)result.residue);

    return 0;
}

