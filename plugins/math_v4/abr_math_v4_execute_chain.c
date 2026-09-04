#include "abr_math_v4_common.h"

abr_plugin_result abr_math_v4_execute_chain(abr_context* ctx,
                                            abr_operator_chain* chain)
{
    /* Correct argument order */
    return abr_operator_chain_execute(chain, ctx);
}

