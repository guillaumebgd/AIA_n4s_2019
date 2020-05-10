/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Optimizes the speed of the clear by checking distance to next wall.
*/

#include <stdlib.h>
#include "ai.h"
#include "relative_values.h"

bool optimized_car_forward(const double mid_lidar_info)
{
    register size_t index = 0;
    char *response = NULL;

    for (; index < NB_SPEED_MILESTONES; index += 1) {
        if (mid_lidar_info >= speed_milestones[index])
            break;
    }
    if (index < NB_SPEED_MILESTONES)
        response = execute_command(speed_forward[index]);
    else
        response = execute_command(DEFAULT_SPEED);
    if (!response)
        return (false);
    free(response);
    return (true);
}