#include "abr.h"
#include "abr_plugin.h"
#include "abr_operator_chain.h"
#include "abr_plugin_result.h"

abr_plugin_result abr_math_v4_execute_chain(abr_context* ctx, abr_operator_chain* chain)
{
    return abr_operator_chain_execute(ctx, chain);
}

