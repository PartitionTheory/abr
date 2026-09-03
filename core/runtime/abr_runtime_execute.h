/*
 * abr_runtime_execute.h — ABR v0.5
 *
 * Runtime execution interface.
 */

#ifndef ABR_RUNTIME_EXECUTE_H
#define ABR_RUNTIME_EXECUTE_H

#include "abr_plugin.h"
#include "abr_plugin_result.h"
#include "abr_runtime_context.h"

abr_plugin_result abr_runtime_execute(
    abr_plugin* plugin,
    abr_context* ctx
);

#endif /* ABR_RUNTIME_EXECUTE_H */

