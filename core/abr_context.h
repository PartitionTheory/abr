/*
 * abr_context.h — ABR v0.5
 *
 * Defines the ABR runtime context structure.
 * The context stores global runtime state used by the VM, plugin registry,
 * dispatch layer, and execution engine.
 *
 * Phoenix Annotation (scflder):
 *   f = front of context lifecycle (creation)
 *   s = second / step after core entry
 *   l = last stage during shutdown
 *   c = clock domain (runtime progression)
 *   d = degree domain (unary expansion)
 *   e = eternal set (persistent invariants)
 *   r = residue domain (post-operation remainder)
 */

#ifndef ABR_CONTEXT_H
#define ABR_CONTEXT_H

#include <stddef.h>

/* ABR runtime context structure. */
typedef struct abr_context {
    size_t clock;     /* c — runtime clock */
    size_t degree;    /* d — unary degree */
    void*  eternal;   /* e — eternal-set invariants */
    void*  residue;   /* r — post-operation remainder */
} abr_context_t;

/* Create a new context (f). */
abr_context_t* abr_context_create(void);

/* Destroy a context (l). */
void abr_context_destroy(abr_context_t* ctx);

#endif /* ABR_CONTEXT_H */

