#ifndef _GARRULUS_ASSERTS_H_
#define _GARRULUS_ASSERTS_H_

#include "defines.h"

#define G_ENABLE_ASSERTS

#if defined(__has_builtin) && !defined(__ibmxl__)
#if __has_builtin(__builtin_debugtrap)
#define g_debug_break() __builtin_debugtrap()
#elif __has_builtin(__debugbreak)
#define g_debug_break() __debugbreak()
#endif
#endif

#if !defined(g_debug_break)
#if defined(__clang__) || defined(__gcc__)
#define g_debug_break() __builtin_trap()
#elif defined(_MSC_VER)
#include <intrin.h>
#define g_debug_break() __debugbreak()
#else
#define g_debug_break() asm { int 3 }
#endif
#endif

GAPI void print_assert_fail(const char* expression, const char* message, const char* file, const int line);

#ifdef G_ENABLE_ASSERTS
#define G_ASSERT(expr)          { if (expr) {} else { print_assert_fail(#expr, "" , __FILE__, __LINE__); g_debug_break(); } }
#define G_ASSERT_MSG(expr, msg) { if (expr) {} else { print_assert_fail(#expr, msg, __FILE__, __LINE__); g_debug_break(); } }

#ifdef _DEBUG
#define G_ASSERT_DEBUG(expr)    { if (expr) {} else { print_assert_fail(#expr, "", __FILE__, __LINE__); g_debug_break(); } }
#else
#define G_ASSERT_DEBUG(expr)
#endif

#else
#define G_ASSERT(expr)
#define G_ASSERT_MSG(expr, msg)
#define G_ASSERT_DEBUG(expr)
#endif

#endif /* ifndef _GARRULUS_ASSERTS_H_ */
