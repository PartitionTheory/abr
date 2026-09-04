/*
 * abr_context.h — ABR v0.5
 *
 * Public definition of the ABR runtime context.
 */

#ifndef ABR_CONTEXT_H
#define ABR_CONTEXT_H

#include <stdint.h>

struct abr_context {
    uint64_t window;
    uint64_t residue;
    const char* plugin_name;
    int status_code;
    const char* error_message;
    uint64_t flags;
};

#endif /* ABR_CONTEXT_H */

