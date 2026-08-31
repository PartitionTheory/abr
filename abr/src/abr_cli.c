/*
 * ABR-Rebirth: Command-Line Interface Implementation
 *
 * Provides minimal CLI runtime initialization, shutdown, and command dispatch.
 */

#include "abr_cli.h"
#include "abr_core.h"
#include "abr_interface.h"
#include "abr_vm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */
/* CLI lifecycle                                                             */
/* ------------------------------------------------------------------------- */

abr_runtime_t *abr_cli_init(void)
{
    abr_runtime_t *rt = abr_init();
    if (!rt) {
        fprintf(stderr, "ABR: failed to initialize runtime\n");
        return NULL;
    }

    /* Initialize VM */
    rt->vm_state = abr_vm_init(rt);
    if (!rt->vm_state) {
        fprintf(stderr, "ABR: failed to initialize VM\n");
        abr_shutdown(rt);
        return NULL;
    }

    return rt;
}

void abr_cli_shutdown(abr_runtime_t *rt)
{
    if (!rt) {
        return;
    }

    /* Shutdown VM */
    if (rt->vm_state) {
        abr_vm_shutdown(rt->vm_state);
        rt->vm_state = NULL;
    }

    /* Shutdown runtime */
    abr_shutdown(rt);
}

/* ------------------------------------------------------------------------- */
/* Command execution                                                          */
/* ------------------------------------------------------------------------- */

int abr_cli_execute(abr_context_t *ctx, const char *command)
{
    if (!ctx || !command) {
        return -1;
    }

    /* Extremely simple stub:
     *
     *   command = "<operator_id>"
     *
     * Later phases will parse full structural mathematics commands.
     */

    int operator_id = atoi(command);
    if (operator_id == 0 && command[0] != '0') {
        fprintf(stderr, "ABR: invalid command '%s'\n", command);
        return -2;
    }

    int rc = abr_interface_execute(ctx, operator_id, NULL);

    if (rc != 0) {
        fprintf(stderr, "ABR: operator %d failed (rc=%d)\n", operator_id, rc);
    }

    return rc;
}

/* ------------------------------------------------------------------------- */
/* Output helper                                                              */
/* ------------------------------------------------------------------------- */

void abr_cli_print(const char *msg)
{
    if (msg) {
        printf("%s\n", msg);
    }
}

