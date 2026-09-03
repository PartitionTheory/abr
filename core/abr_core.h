/*
 * abr_core.h — ABR v0.5
 *
 * Public interface for the ABR core runtime.
 * Provides initialization, shutdown, and access to the global context.
 *
 * Phoenix Annotation (scflder):
 *   f = front of runtime entry
 *   s = second / step in initialization chain
 *   l = last stage before VM activation
 *   c = clock domain exposed through context
 *   d = degree domain (unary expansion)
 *   e = eternal set (persistent invariants)
 *   r = residue domain (post-operation remainder)
 */

#ifndef ABR_CORE_H
#define ABR_CORE_H

#include "abr_context.h"

/* Initialize the ABR core runtime (f → s → l sequence). */
int abr_core_init(void);

/* Shut down the ABR core runtime (clear r, preserve e). */
void abr_core_shutdown(void);

/* Access the global context (exposes c and d domains). */
abr_context_t* abr_core_context(void);

#endif /* ABR_CORE_H */

