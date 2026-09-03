/*
 * abr_dispatch.h — ABR v0.5
 *
 * Execution dispatcher interface.
 */

#ifndef ABR_DISPATCH_H
#define ABR_DISPATCH_H

#include <stddef.h>
#include "abr_system.h"
#include "abr_plugin_result.h"

abr_plugin_result abr_dispatch_single(
    abr_system* sys,
    const char* name
);

abr_plugin_result abr_dispatch_pipeline(
    abr_system* sys,
    const char** names,
    size_t count
);

#endif /* ABR_DISPATCH_H */

