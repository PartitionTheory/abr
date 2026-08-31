#include "abr_cli.h"
#include "abr_interface.h"
int main(int argc, char **argv)
{
    abr_runtime_t *rt = abr_cli_init();
    if (!rt) {
        return 1;
    }

    abr_context_t *ctx = abr_context_create(rt);
    if (!ctx) {
        abr_cli_shutdown(rt);
        return 1;
    }

    if (argc > 1) {
        abr_cli_execute(ctx, argv[1]);
    }

    abr_context_destroy(ctx);
    abr_cli_shutdown(rt);
    return 0;
}

