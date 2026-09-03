/*
 * sdk.h — ABR v0.5
 *
 * Defines the ABR SDK interface.
 * The SDK provides a minimal ABI boundary between ABR core and external
 * tools such as CLIs, GUIs, and future VM consumers.
 *
 * Phoenix Annotation (scflder):
 *   f = front of SDK entry
 *   s = second / step in SDK call
 *   l = last stage before return
 *   c = clock domain (SDK may read context clock)
 *   d = degree domain (SDK may expose unary degree)
 *   e = eternal set (SDK may expose invariants)
 *   r = residue domain (SDK may expose last result)
 */

#ifndef ABR_SDK_H
#define ABR_SDK_H

#include "abr_context.h"

/* Initialize the SDK (f). */
int abr_sdk_init(abr_context_t* ctx);

/* Shut down the SDK (l). */
void abr_sdk_shutdown(abr_context_t* ctx);

#endif /* ABR_SDK_H */

