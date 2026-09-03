/*
 * abr_system.h — ABR v0.5
 *
 * System-layer runtime interface.
 */

#ifndef ABR_SYSTEM_H
#define ABR_SYSTEM_H

#include <stddef.h>
#include "abr_runtime_context.h"
#include "abr_plugin_result.h"

typedef struct abr_system
{
    int initialized;
    abr_context* ctx;

} abr_system;

void abr_system_init(abr_system* sys);
void abr_system_destroy(abr_system* sys);

abr_plugin_result abr_system_execute_plugin(
    abr_system* sys,
    const char* name
);

abr_plugin_result abr_system_execute_pipeline(
    abr_system* sys,
    const char** names,
    size_t count
);

#endif /* ABR_SYSTEM_H */

