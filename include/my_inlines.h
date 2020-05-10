/*
** EPITECH PROJECT, 2019
** Libmy Guillaume BOGARD-COQUARD 2019
** File description:
** Inlines for libmy.
*/

#ifndef MY_INLINES_H_
#define MY_INLINES_H_

#include <stdlib.h>
#include "my.h"

static inline void my_free_char_array(char **array)
{
    my_free_2d((void **)array);
}

static inline void my_free_int_array(int **array)
{
    my_free_2d((void **)array);
}

static inline void my_free_set_null_char_array(char ***array)
{
    my_free_2d((void **)(*array));
    *array = NULL;
}

static inline void my_free_set_null_array(void ***array)
{
    my_free_2d(*array);
    *array = NULL;
}

static inline void my_free_set_null_char_ptr(char **ptr)
{
    if (!(*ptr))
        return;
    free(*ptr);
    *ptr = NULL;
}

static inline void my_free_set_null(void **ptr)
{
    if (!(*ptr))
        return;
    free(*ptr);
    *ptr = NULL;
}

#endif /* MY_INLINES_H_ */