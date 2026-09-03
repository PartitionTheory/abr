/*
 * abr_runtime_pipeline.h — ABR v0.5
 *
 * Multi-plugin pipeline interface.
 */

#ifndef ABR_RUNTIME_PIPELINE_H
#define ABR_RUNTIME_PIPELINE_H

#include <stddef.h>
#include "abr_plugin.h"
#include "abr_plugin_result.h"
#include "abr_runtime_context.h"

abr_plugin_result abr_runtime_pipeline_execute(
    abr_plugin** plugins,
    size_t count,
    abr_context* ctx
);

#endif /* ABR_RUNTIME_PIPELINE_H */

