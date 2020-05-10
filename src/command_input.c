/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Handles the input we want to give to the n4s binary.
*/

#include <stdlib.h>
#include "my.h"

char *execute_command(const char *command)
{
    char *answer_to_command = NULL;

    my_putstr(command);
    return (get_next_line(0, 4096));
}