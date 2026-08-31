#include <stdio.h>
#include <stdlib.h>        // <-- required for atoi()
#include "abr_stream.h"    // <-- must declare abr_stream_split()


int cli_split_main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "usage: abr split <file|-> <bitWidth>\n");
        return 1;
    }

    const char *path = argv[2];
    int bitWidth = atoi(argv[3]);

    return abr_stream_split(path, bitWidth);
}

