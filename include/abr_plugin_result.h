/*
 * abr_plugin_result.h — ABR v0.5
 *
 * Unified result type returned by operator chains and plugin execution.
 */

#ifndef ABR_PLUGIN_RESULT_H
#define ABR_PLUGIN_RESULT_H

#include <stdint.h>
#include "windowset.h"

/*
 * A plugin result is simply a WindowSet plus a status code.
 * Status codes allow operator chains to signal:
 *   - success
 *   - failure
 *   - short‑circuit
 *   - invariant violation
 */
typedef enum {
    ABR_RESULT_OK = 0,
    ABR_RESULT_FAIL = 1,
    ABR_RESULT_SHORT = 2,
    ABR_RESULT_INVARIANT = 3
} abr_result_code;

/*
 * Unified result structure.
 */
typedef struct abr_plugin_result {
    WindowSet ws;
    abr_result_code code;
} abr_plugin_result;

#endif /* ABR_PLUGIN_RESULT_H */

