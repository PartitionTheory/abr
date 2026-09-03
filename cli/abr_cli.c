/*
 * abr_cli.c — ABR v0.5
 *
 * Canonical command-line interface for ABR.
 *
 * Responsibilities:
 *   - parse CLI arguments
 *   - initialize ABR system
 *   - execute single plugins or pipelines
 *   - print results and errors
 *
 * Phoenix Annotation (scflder):
 *   f = front (CLI input)
 *   s = second (system + runtime)
 *   l = last (CLI output)
 *   d = degree domain (argument count)
 *   r = residue domain (execution result)
 */

#include "abr_cli.h"
#include "abr_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print result */
static void abr_cli_print_result(
    const char* label,
    abr_plugin_result result,
    abr_context* ctx
)
{
    printf("%s:\n", label);
    printf("  window:  %llu\n", (unsigned long long)result.window);
    printf("  residue: %llu\n", (unsigned long long)result.residue);

    if (ctx->status_code != 0)
    {
        printf("  error:   %s\n", ctx->error_message);
        printf("  plugin:  %s\n", ctx->plugin_name);
    }
}

/* CLI entrypoint */
int abr_cli_main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("usage:\n");
        printf("  abr <window> <plugin>\n");
        printf("  abr <window> <plugin1> <plugin2> ...\n");
        return 1;
    }

    /* Parse initial window */
    uint64_t window = strtoull(argv[1], NULL, 0);

    /* Initialize system */
    abr_system sys;
    abr_system_init(&sys);

    /* Set initial window */
    sys.ctx->window  = window;
    sys.ctx->residue = 0;

    /* Single plugin */
    if (argc == 3)
    {
        const char* plugin_name = argv[2];

        abr_plugin_result result =
            abr_system_execute_plugin(&sys, plugin_name);

        abr_cli_print_result("result", result, sys.ctx);
    }
    else
    {
        /* Pipeline */
        size_t count = argc - 2;
        const char** names =
            (const char**)malloc(sizeof(char*) * count);

        for (size_t i = 0; i < count; i++)
            names[i] = argv[i + 2];

        abr_plugin_result result =
            abr_system_execute_pipeline(&sys, names, count);

        abr_cli_print_result("pipeline result", result, sys.ctx);

        free(names);
    }

    abr_system_destroy(&sys);
    return 0;
}

