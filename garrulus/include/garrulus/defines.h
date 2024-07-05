#ifndef _GARRULUS_DEFINES_H_
#define _GARRULUS_DEFINES_H_

#ifdef CWEXPORT
#define GAPI __attribute__((visibility("default")))
#else
#define GAPI
#endif

#endif /* ifndef _GARRULUS_DEFINES_H_ */
