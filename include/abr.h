/*
 * abr.h — ABR v0.5
 *
 * Canonical ABI for the Arbitrary Bit Read system.
 *
 * This file defines:
 *   - plugin struct
 *   - plugin result struct
 *   - plugin factory signature
 *   - runtime context
 *   - execution signature
 *   - destroy signature
 *   - ABI-stable types for all subsystems
 *
 * Phoenix Annotation (scflder):
 *   f = front (ABI input)
 *   s = second (ABI resolution)
 *   l = last (ABI output)
 *   d = degree domain (ABI width)
 *   r = residue domain (ABI propagation)
 */

#ifndef ABR_H
#define ABR_H

#include <stdint.h>

/* Forward declarations */
struct abr_context;
struct abr_plugin;

/* Plugin result */
typedef struct abr_plugin_result
{
    uint64_t window;
    uint64_t residue;

} abr_plugin_result;

/* Plugin function signatures */
typedef void (*abr_plugin_create_fn)(struct abr_plugin*);
typedef abr_plugin_result (*abr_plugin_execute_fn)(
    struct abr_plugin*,
    struct abr_context*
);
typedef void (*abr_plugin_destroy_fn)(struct abr_plugin*);

/* Plugin struct */
typedef struct abr_plugin
{
    const char* name;

    abr_plugin_create_fn  create;
    abr_plugin_execute_fn execute;
    abr_plugin_destroy_fn destroy;

    void* data;

} abr_plugin;

/* Plugin factory */
typedef abr_plugin* (*abr_plugin_factory)(void);

/* Runtime context */
typedef struct abr_context
{
    uint64_t window;
    uint64_t residue;

    const char* plugin_name;
    int status_code;
    const char* error_message;

    uint32_t flags;

} abr_context;

#endif /* ABR_H */

