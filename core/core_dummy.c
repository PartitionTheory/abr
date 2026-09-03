/*
 * core_dummy.c — ABR v0.5
 *
 * A placeholder core module used for testing, scaffolding, and ensuring
 * the build system remains stable as new core transforms are added.
 *
 * Phoenix Annotation (scflder):
 *   f = front of dummy entry
 *   s = second / step (no-op transform)
 *   l = last stage (return unchanged)
 *   c = clock domain (increment for testing)
 *   d = degree domain (unchanged)
 *   e = eternal set (preserved)
 *   r = residue domain (unchanged)
 */

#include "abr_context.h"

/* -------------------------------------------------------------------------
 * core_dummy
 *
 * A no-op core transform. Increments the clock and returns success.
 * ------------------------------------------------------------------------- */
int core_dummy(abr_context_t* ctx)
{
    if (!ctx)
        return -1;

    /* c = increment clock domain */
    ctx->clock++;

    /* s = no-op transform */

    /* l = return unchanged */
    return 0;
}

