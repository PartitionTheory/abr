#include <stdio.h>
#include <stdlib.h>
#include "abr_stream.h"

int cli_join_main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "usage: abr join <hexFile|-> <bitWidth> <originalBits>\n");
        return 1;
    }

    const char *hexPath = argv[2];
    int bitWidth = atoi(argv[3]);
    int originalBits = atoi(argv[4]);

    return abr_stream_join(hexPath, bitWidth, originalBits);
}

