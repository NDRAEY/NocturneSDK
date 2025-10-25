#ifndef SAYORISDK_STDDEF_H
#define SAYORISDK_STDDEF_H

#define SAYORIOS

#define NULL (0)

#define SAYORI_INLINE static inline __attribute__((always_inline))

#define KB (1 << 10)
#define MB (1 << 20)
#define GB (1 << 30)

#define ALIGN(value, align) ((value) + ((-(value)) & ((align) - 1)))
#define IS_ALIGNED(value, align) ((value) % (align) == 0)

#define ON_NULLPTR(_, __)

#include <stdint.h>

typedef uint32_t size_t;
typedef int32_t ssize_t;

typedef int32_t wchar_t;

typedef ssize_t ptrdiff_t;

#endif //SAYORISDK_STDDEF_H
