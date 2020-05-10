/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Gets a double from a string.
*/

#include "my.h"

double my_getdouble(const char *str)
{
    register size_t index = 0;
    double nb = 0;
    double divider = 0.1;

    if (!str)
        return (0);
    for (; str[index] && my_isnum(str[index]); index += 1)
        nb = nb * 10 + (str[index] - 48);
    if (str[index] == '.') {
        index += 1;
        for (; str[index] && my_isnum(str[index]); index += 1) {
            nb = nb + ((str[index] - 48) * divider);
            divider *= 0.1;
            }
    }
    return (nb);
}
