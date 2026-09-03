/*
 * abr_dispatch.h — ABR v0.5
 *
 * Public interface for the ABR dispatch layer.
 * Dispatch routes execution requests from the core runtime to the VM and
 * plugin registry. It is the structural controller of ABR.
 *
 * Phoenix Annotation (scflder):
 *   f = front of dispatch entry
 *   s = second / step in plugin selection
 *   l = last stage before VM execution
 *   c = clock domain incremented on dispatch
 *   d = degree domain may be adjusted by plugin metadata
 *   e = eternal set preserved across dispatch
 *   r = residue returned after VM execution
 */

#ifndef ABR_DISPATCH_H
#define ABR_DISPATCH_H

/* Execute a plugin by name (f → s → l sequence). */
int abr_dispatch_execute(const char* plugin_name);

#endif /* ABR_DISPATCH_H */

