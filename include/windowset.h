#ifndef WINDOWSET_H
#define WINDOWSET_H

#include <stdint.h>

/* A windowset is a simple pair of window + residue */
typedef struct windowset {
    uint64_t window;
    uint64_t residue;
} windowset;

#endif /* WINDOWSET_H */

