/*
 * abr_plugins_builtin.h — ABR v0.5
 *
 * Built‑in plugin family index.
 * Provides:
 *   - declarations for built‑in plugin factories
 *   - unified include point for loader and registry
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (factory resolution)
 *   l = last (plugin instance)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#ifndef ABR_PLUGINS_BUILTIN_H
#define ABR_PLUGINS_BUILTIN_H

#include "abr_plugin.h"

/* Identity plugin factory */
abr_plugin* abr_plugin_identity_factory(void);

/* NOT plugin factory */
abr_plugin* abr_plugin_not_factory(void);

#endif /* ABR_PLUGINS_BUILTIN_H */

