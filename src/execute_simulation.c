/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Executes the ai algorithm.
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"
#include "my_inlines.h"
#include "ai.h"

static bool execute_speed(char **lidar_info)
{
    char **parsed_lidar_info = NULL;
    double mid_liddar_info = 0;

    parsed_lidar_info = PARSE_RESPONSE(*lidar_info, true);
    *lidar_info = NULL;
    mid_liddar_info = my_getdouble(GET_INFO(parsed_lidar_info)[MID_LIDAR_POS]);
    if (!optimized_car_forward(mid_liddar_info))
        return (false);
    my_free_char_array(parsed_lidar_info);
    return (true);
}

static bool execute_rotation(char **lidar_info)
{
    char **parsed_lidar_info = NULL;
    double mid_liddar_info = 0;

    parsed_lidar_info = PARSE_RESPONSE(*lidar_info, true);
    *lidar_info = NULL;
    mid_liddar_info = my_getdouble(GET_INFO(parsed_lidar_info)[MID_LIDAR_POS]);
    if (!handle_direction(GET_INFO(parsed_lidar_info), mid_liddar_info))
        return (false);
    my_free_char_array(parsed_lidar_info);
    return (true);
}

void execute_simulation(void)
{
    char *lidar_info = NULL;

    while (1) {
        lidar_info = execute_command("GET_INFO_LIDAR\n");
        if (is_track_cleared(lidar_info, false))
            break;
        if (!execute_speed(&lidar_info))
            break;
        lidar_info = execute_command("GET_INFO_LIDAR\n");
        if (is_track_cleared(lidar_info, false))
            break;
        if (!execute_rotation(&lidar_info))
            break;
    }
    if (lidar_info)
        free(lidar_info);
}