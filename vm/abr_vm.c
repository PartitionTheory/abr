/*
 * abr_vm.c — ABR v0.5
 *
 * Canonical virtual machine runtime for ABR.
 *
 * Responsibilities:
 *   - maintain VM state
 *   - execute plugins by name
 *   - execute pipelines
 *   - provide REPL-style execution loop
 *   - integrate with system-layer runtime
 *
 * Phoenix Annotation (scflder):
 *   f = front (VM input)
 *   s = second (system + runtime)
 *   l = last (VM output)
 *   d = degree domain (instruction count)
 *   r = residue domain (execution result)
 */

#include "abr_vm.h"
#include "abr_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Initialize VM */
void abr_vm_init(abr_vm* vm)
{
    if (!vm)
        return;

    abr_system_init(&vm->sys);
    vm->running = 1;
}

/* Destroy VM */
void abr_vm_destroy(abr_vm* vm)
{
    if (!vm)
        return;

    abr_system_destroy(&vm->sys);
    vm->running = 0;
}

/* Execute a single instruction */
abr_plugin_result abr_vm_execute_instruction(
    abr_vm* vm,
    const char* instr
)
{
    return abr_system_execute_plugin(&vm->sys, instr);
}

/* Execute a pipeline instruction */
abr_plugin_result abr_vm_execute_pipeline(
    abr_vm* vm,
    const char** names,
    size_t count
)
{
    return abr_system_execute_pipeline(&vm->sys, names, count);
}

/* REPL loop */
void abr_vm_repl(abr_vm* vm)
{
    char buffer[256];

    printf("ABR v0.5 VM — type 'exit' to quit\n");

    while (vm->running)
    {
        printf("abr> ");
        if (!fgets(buffer, sizeof(buffer), stdin))
            break;

        /* Trim newline */
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "exit") == 0)
        {
            vm->running = 0;
            break;
        }

        /* Parse pipeline */
        char* tokens[32];
        size_t count = 0;

        char* tok = strtok(buffer, " ");
        while (tok && count < 32)
        {
            tokens[count++] = tok;
            tok = strtok(NULL, " ");
        }

        if (count == 0)
            continue;

        abr_plugin_result result;

        if (count == 1)
        {
            result = abr_vm_execute_instruction(vm, tokens[0]);
        }
        else
        {
            const char** names =
                (const char**)malloc(sizeof(char*) * count);

            for (size_t i = 0; i < count; i++)
                names[i] = tokens[i];

            result = abr_vm_execute_pipeline(vm, names, count);

            free(names);
        }

        printf("window:  %llu\n", (unsigned long long)result.window);
        printf("residue: %llu\n", (unsigned long long)result.residue);

        if (vm->sys.ctx->status_code != 0)
        {
            printf("error:   %s\n", vm->sys.ctx->error_message);
            printf("plugin:  %s\n", vm->sys.ctx->plugin_name);
        }
    }
}

