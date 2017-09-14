#include "grow-array.h"

#include <stdlib.h>
#include <string.h>

void *grow_array_using_realloc(void *a, uint32_t *size, uint32_t target_size)
{
    uint32_t n = *size;
    while (target_size > n) {
        uint32_t m = (n + 1) * 3 / 2;
        if (m < n)
            n = 0xffffffff;
        else
            n = m;
    }
    void *next_array = realloc(a, n);
    if (!next_array)
        abort();
    memset(next_array + *size, 0, n - *size);
    *size = n;
    return next_array;
}