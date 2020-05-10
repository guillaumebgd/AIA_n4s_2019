/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Handles the taken rotations.
*/

#include <stdlib.h>
#include "my.h"
#include "ai.h"
#include "relative_values.h"

static bool handle_right_or_left(const double car_tilt,
                                const char left_right_turn[])
{
    char *response = NULL;

    my_putstr("WHEELS_DIR:");
    if (car_tilt < 0.0)
        my_putchar('-');
    my_putstr(left_right_turn);
    response = get_next_line(0, 4096);
    if (!response)
        return (false);
    free(response);
    return (true);
}

bool handle_direction(char **parsed_lidar_info, const double mid_liddar_info)
{
    register size_t index = 1;
    const double left_info = my_getdouble(parsed_lidar_info[LEFT_LIDAR_POS]);
    const double right_info = my_getdouble(parsed_lidar_info[RIGHT_LIDAR_POS]);
    const double dif_left_right = left_info - right_info;

    for (; index < NB_ROTATION_MILESTONES; index += 1) {
        if (mid_liddar_info >= rotation_milestones[index])
            break;
    }
    if (index < NB_ROTATION_MILESTONES) {
        if (!handle_right_or_left(dif_left_right, rotate_sideways[index]))
            return (false);
    } else {
        if (!handle_right_or_left(dif_left_right, DEFAULT_ROTATION))
            return (false);
    }
    return (true);
}