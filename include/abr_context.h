#ifndef ABR_CONTEXT_H
#define ABR_CONTEXT_H

#include "abr.h"

/*
 * Phoenix v0.4-greenbuild:
 * ABR Global Execution Context
 *
 * The context stores all subsystem state:
 * - operator registry
 * - plugin registry
 * - VM state
 * - dispatch tables
 * - stream buffers
 * - synthetic operator sets
 */

typedef struct abr_context {

    /* Operator registry root */
    void* operator_registry;

    /* Plugin registry root */
    void* plugin_registry;

    /* Synthetic operator sets */
    void* synth_sets;

    /* VM global state */
    void* vm_state;

    /* Stream subsystem */
    void* stream_state;

    /* Dispatch tables */
    void* dispatch_state;

} abr_context_t;

/* Allocate and initialize a new ABR context */
abr_context_t* abr_context_create(struct abr_runtime* rt);

/* Destroy an ABR context */
void abr_context_destroy(abr_context_t* ctx);

#endif

