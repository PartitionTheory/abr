/*
 * abr_math_v4_common.h — ABR v0.5
 *
 * Shared definitions used by all math_v4 plugins.
 */

#ifndef ABR_MATH_V4_COMMON_H
#define ABR_MATH_V4_COMMON_H

#include "abr.h"
#include "abr_plugin.h"
#include "abr_operator_chain.h"
#include "abr_operators.h"
#include "abr_plugin_registry.h"
#include "abr_plugin_result.h"
#include "abr_math_v4_common.h"

/* Shared helper: execute an operator chain in the math_v4 context */
abr_plugin_result abr_math_v4_execute_chain(abr_context* ctx,
                                            abr_operator_chain* chain);

#endif /* ABR_MATH_V4_COMMON_H */

