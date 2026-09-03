/*
 * core_dummy.h — ABR v0.5
 *
 * Dummy placeholder module for the core subsystem.
 * Provides a stable symbol required by the build system and ABI.
 *
 * Phoenix Annotation (scflder):
 *   f = front (entry point)
 *   l = last (terminal no-op)
 */

#ifndef ABR_CORE_DUMMY_H
#define ABR_CORE_DUMMY_H

/* Dummy function — no operation, stable ABI symbol. */
void abr_core_dummy(void);

#endif /* ABR_CORE_DUMMY_H */

