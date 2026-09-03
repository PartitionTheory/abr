/*
 * core_dummy.c — ABR v0.5
 *
 * Dummy placeholder module for the core subsystem.
 * Provides a stable symbol required by the build system and ABI.
 *
 * Phoenix Annotation (scflder):
 *   f = front (entry point)
 *   l = last (terminal no-op)
 */

#include "core_dummy.h"

/* Stable ABI symbol — intentionally does nothing. */
void abr_core_dummy(void)
{
    /* no-op */
}

