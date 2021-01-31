/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>

#undef READ_SIZE
#ifndef READ_SIZE
#define READ_SIZE 0x0fff
#endif /*READ_SIZE*/

__always_inline int __nonnull(()) my_strlen(const char *str)
{
    int i;

    if (str == NULL)
        return (-1);
    for (i = 0; str[i]; ++i);
    return (i);
}

__always_inline void * __nonnull(()) my_memcpy(void *restrict dest,
            const void *restrict src, size_t len)
{
    char *cdest = dest;
    const char *csrc = src;

    for (; len--; (*cdest++) = (*csrc++));
    return (dest);
}

__always_inline void __nonnull(()) my_bzero(void *string, size_t size)
{
    for (unsigned char *string2 = (unsigned char *)string; size > 0; --size)
        (*string2++) = '\0';
}

__always_inline void *__nonnull(()) my_memalloc(size_t size, bool is_arr)
{
    void *memory = malloc(size);

    if (memory) {
        if (!is_arr) my_bzero(memory, size);
        return (memory);
    }
    return (NULL);
}

__always_inline char *__nonnull((1)) my_strdup(char *const restrict src)
{
    size_t len = my_strlen(src) + 2;
    void *new = my_memalloc(len, false);

    return ((char *)my_memcpy(new, src, len));
}

typedef struct __msize_t
{
    int i_bf : 13;
    int i_s : 13;
    int l : 13;
    unsigned char *s;
    unsigned char bf[READ_SIZE];
} msize_t;

char *get_next_line(int const __fd) __nonnull(())
__attribute_pure__;

#endif /* !GET_NEXT_LINE_H_ */