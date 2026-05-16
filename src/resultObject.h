#ifndef RESULT_OBJECT_H
#include "compilerMacros.h"
#define RESULT_OBJECT_H
#endif // RESULT_OBJECT_H

// Everything below here can be included multiple times to generate result
// objects for each type passed

#ifndef RESULT_OBJECT_TYPE
#error "Template type RESULT_OBJECT_TYPE undefined for <resultObject.h>"
#endif

#ifndef RESULT_OBJECT_TYPE_NAME
#error                                                                         \
    "Template type name RESULT_OBJECT_TYPE_NAME undefined for <resultObject.h>"
#endif

#define RESULT_OBJECT JOIN(RESULT_OBJECT_TYPE_NAME, ResultObject)

/* Result Object Struct used to provide numerical return codes to functions
 * that would normally return a pointer or value. Normally a union of a pointer
 * and value of the requested type is returned, but the
 * RESULT_OBJECT_ONLY_POINTER and RESULT_OBJECT_ONLY_VALUE macros can be defined
 * to only include one of the requested options. This is particularly useful
 * with particularly large user defined types or particularly small primitives.
 * RESULT_OBJECT_TYPE *pointer
 *     The pointer returned by the function on a success.
 * RESULT_OBJECT_TYPE value
 *     The value returned by the function on a success.
 * int returnCode
 *     The return code returned by the function. A non-zero return code
 *     indicates that some recovery action should occur. Handling this is left
 *     to the user.
 */
typedef struct RESULT_OBJECT {
#ifdef RESULT_OBJECT_ONLY_POINTER
  RESULT_OBJECT_TYPE *pointer;
#elif defined(RESULT_OBJECT_ONLY_VALUE)
  RESULT_OBJECT_TYPE value;
#else
  union {
    RESULT_OBJECT_TYPE *pointer;
    RESULT_OBJECT_TYPE value;
  };
#endif
  int returnCode;
} RESULT_OBJECT;

// Undefines RESULT_OBJECT to avoid clashing with subsequent includes
#undef RESULT_OBJECT
#undef RESULT_OBJECT_TYPE
#undef RESULT_OBJECT_TYPE_NAME
#undef RESULT_OBJECT_ONLY_POINTER
#undef RESULT_OBJECT_ONLY_VALUE
