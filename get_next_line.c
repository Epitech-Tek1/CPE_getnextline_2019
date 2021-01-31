/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#include "get_next_line.h"
#undef get_next_line
#ifndef __gnl
#define __gnl get_next_line
#endif /*__gnl*/

char *__gnl(int const __fd)
{
    static msize_t __msize_t;

    if (!__msize_t.bf[__msize_t.i_bf]) {
        __msize_t.l = read(__fd, __msize_t.bf, READ_SIZE);
        __msize_t.bf[__msize_t.l] = (__msize_t.i_bf = 0) ? '\0' : 0;
    }
    __msize_t.s = my_memalloc(READ_SIZE + 1, false);
    while (__msize_t.bf[__msize_t.i_bf] && __msize_t.bf[__msize_t.i_bf] != '\n')
        __msize_t.s[__msize_t.i_s++] = __msize_t.bf[__msize_t.i_bf++];
    if (__msize_t.bf[__msize_t.i_bf] == '\n')
        return (__msize_t.i_s = 0) ? (NULL) : (__msize_t.s);
    return (__gnl(__fd));
}