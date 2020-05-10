/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Checks if the current track is cleared.
*/

#include <stdlib.h>
#include "my.h"

bool is_track_cleared(char *output, const bool do_free)
{
    register ssize_t i = my_strlen(output) - 1;
    bool is_cleared = false;

    if (i <= 0)
        return (i < 0) ? true : false;
    for (; i >= 0 && output[i] && output[i] != ':'; i -= 1);
    i -= 1;
    for (; i >= 0 && output[i] && output[i] != ':'; i -= 1);
    i += 1;
    if (my_str_eq_str_n(&output[i], "Track Cleared", 13)) {
        is_cleared = true;
    }
    if (do_free && output)
        free(output);
    return (is_cleared);
}