#ifndef _GARRULUS_DEFINES_H_
#define _GARRULUS_DEFINES_H_

#ifdef CW_EXPORT
#define G_API __attribute__((visibility("default")))
#else
#define G_API
#endif

#endif /* ifndef _GARRULUS_DEFINES_H_ */
