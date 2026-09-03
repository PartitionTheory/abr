/*
 * abr_exec.h — ABR v0.5
 *
 * Public interface for the ABR execution coordinator.
 * Provides the ABI for plugin execution and defines the bridge between
 * dispatch and the VM.
 *
 * Phoenix Annotation (scflder):
 *   f = front of execution entry
 *   s = second / step in plugin ABI selection
 *   l = last stage before VM execution
 *   c = clock domain incremented on execution
 *   d = degree domain may be adjusted by plugin metadata
 *   e = eternal set preserved across execution
 *   r = residue returned after VM execution
 */

#ifndef ABR_EXEC_H
#define ABR_EXEC_H

#include "abr_plugin.h"

/* Execute a plugin using the correct ABI (f → s → l sequence). */
int abr_exec_plugin(abr_plugin_t* plugin);

#endif /* ABR_EXEC_H */

