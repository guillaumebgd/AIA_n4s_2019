/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** duplicates a string upto a certain list of characters and increases an index
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup_char_i(const char *template, const char c, size_t *index)
{
    char *result = NULL;
    int size = my_strlen_until_c(template, c);
    int count_dup = 0;

    if (!template)
        return (NULL);
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return (NULL);
    result[size] = '\0';
    while (count_dup < size) {
        result[count_dup] = template[count_dup];
        count_dup += 1;
    }
    *index += count_dup;
    return (result);
}