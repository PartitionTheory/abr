#include <stdio.h>
#include <string.h>

int cli_split_main(int argc, char **argv);
int cli_join_main(int argc, char **argv);

int abr_cli_dispatch(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr,
            "usage:\n"
            "  abr split <file|-> <bitWidth>\n"
            "  abr join  <hexFile|-> <bitWidth> <originalBits>\n"
        );
        return 1;
    }

    const char *cmd = argv[1];

    if (strcmp(cmd, "split") == 0)
        return cli_split_main(argc, argv);

    if (strcmp(cmd, "join") == 0)
        return cli_join_main(argc, argv);

    fprintf(stderr, "ABR: invalid command '%s'\n", cmd);
    return 1;
}

