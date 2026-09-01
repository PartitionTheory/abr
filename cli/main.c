#include "abr_cli.h"
#include "abr_interface.h"
#include "abr_plugin_loader.h"
#include "abr_plugin.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    const char* opt_plugin = NULL;

    /* Parse CLI arguments */
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--plugin") == 0 && i + 1 < argc) {
            opt_plugin = argv[++i];
            continue;
        }
    }

    abr_runtime_t *rt = abr_cli_init();
    if (!rt) {
        return 1;
    }

    abr_context_t *ctx = abr_context_create(rt);
    if (!ctx) {
        abr_cli_shutdown(rt);
        return 1;
    }

    /* --------------------------------------------------------------------- */
    /* v0.4 plugin execution path                                             */
    /* --------------------------------------------------------------------- */
    if (opt_plugin) {
        size_t plugin_count = 0;
        abr_plugin** plugins = abr_plugin_load_all(&plugin_count);

        if (!plugins || plugin_count == 0) {
            fprintf(stderr, "ABR: no plugins available\n");
            abr_context_destroy(ctx);
            abr_cli_shutdown(rt);
            return 1;
        }

        abr_plugin* selected = NULL;

        for (size_t i = 0; i < plugin_count; i++) {
            if (strcmp(plugins[i]->name, opt_plugin) == 0) {
                selected = plugins[i];
                break;
            }
        }

        if (!selected) {
            fprintf(stderr, "ABR: unknown plugin '%s'\n", opt_plugin);
            abr_plugin_free_all(plugins, plugin_count);
            abr_context_destroy(ctx);
            abr_cli_shutdown(rt);
            return 1;
        }

        abr_plugin_input input = {0};
        abr_plugin_result result = selected->execute(&input);

        printf("%s\n", result.message);

        abr_plugin_free_all(plugins, plugin_count);
        abr_context_destroy(ctx);
        abr_cli_shutdown(rt);
        return 0;
    }

    /* --------------------------------------------------------------------- */
    /* Legacy operator execution path                                         */
    /* --------------------------------------------------------------------- */
    if (argc > 1) {
        abr_cli_execute(ctx, argv[1]);
    }

    abr_context_destroy(ctx);
    abr_cli_shutdown(rt);
    return 0;
}

