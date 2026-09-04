/*
 * abr_vm.c — ABR v0.5 Virtual Machine
 *
 * Provides a minimal REPL-style VM that loads plugins, executes them,
 * and prints window/residue results. This is intentionally simple and
 * serves as the reference VM for ABR v0.5.
 */

#include "abr_vm.h"
#include "abr.h"
#include "abr_plugin_loader.h"
#include "abr_runtime_execute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_prompt(void)
{
    printf("abr> ");
    fflush(stdout);
}

static void print_result(struct abr_context* ctx)
{
    printf("window=%llu residue=%llu\n",
           (unsigned long long)ctx->window,
           (unsigned long long)ctx->residue);
}

void abr_vm_run(void)
{
    char line[256];
    struct abr_context ctx;
    abr_runtime_context_init(&ctx);

    printf("ABR v0.5 VM — type 'exit' to quit\n");

    while (1) {
        print_prompt();

        if (!fgets(line, sizeof(line), stdin))
            break;

        if (strncmp(line, "exit", 4) == 0)
            break;

        /* trim newline */
        line[strcspn(line, "\n")] = 0;

        struct abr_plugin* plugin = abr_plugin_loader_load(line);
        if (!plugin) {
            printf("unknown plugin: %s\n", line);
            continue;
        }

        plugin->create(plugin);
        struct abr_plugin_result r = plugin->execute(plugin, &ctx);
        plugin->destroy(plugin);

        ctx.window  = r.window;
        ctx.residue = r.residue;

        print_result(&ctx);
    }

    printf("VM terminated.\n");
}

