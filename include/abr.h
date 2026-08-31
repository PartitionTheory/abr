#ifndef ABR_H
#define ABR_H

/*
 * ABR-Rebirth: Synthetic Mathematics Runtime
 * Root public API header.
 *
 * This header exposes the minimal, stable entry points into the ABR system.
 * All external code should include this file, not internal subsystem headers.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque handles for core runtime objects */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_context abr_context_t;

/*
 * Initialize the ABR runtime.
 * Returns a pointer to an abr_runtime_t on success, or NULL on failure.
 */
abr_runtime_t *abr_init(void);

/*
 * Shut down the ABR runtime and release all resources.
 */
void abr_shutdown(abr_runtime_t *rt);

/*
 * Create a new computation context bound to a runtime.
 * Returns a pointer to an abr_context_t on success, or NULL on failure.
 */
abr_context_t *abr_context_create(abr_runtime_t *rt);

/*
 * Destroy a computation context and release its resources.
 */
void abr_context_destroy(abr_context_t *ctx);

/*
 * Version query for external systems and tooling.
 * Returns a constant, null-terminated version string.
 */
const char *abr_version(void);

#ifdef __cplusplus
}
#endif

#endif /* ABR_H */

