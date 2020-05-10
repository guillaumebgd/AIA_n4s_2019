/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** AI's program header.
*/

#ifndef AI_H_
#define AI_H_

#include <stdbool.h>
#include "my.h"

/////////////////////////////////////////////////

#define LEFT_LIDAR_POS (1)
#define RIGHT_LIDAR_POS (31)

#define MID_LIDAR_POS (15)

#define PARSE_RESPONSE(response, do_free) \
            my_parse_str(response, ":", do_free)

#define GET_INFO(parsed_lidar_info) (&parsed_lidar_info[3])

/////////////////////////////////////////////////


//Passes a given command as input of n4s and returns the parsed response.
char *execute_command(const char *command);

//Executes steps for the car to clear the track.
void execute_simulation(void);

//Checks whether the given output matches to a 'cleared track' info.
bool is_track_cleared(char *output, const bool do_free);

//Optimizes the speed of the clear by checking distance to next wall
//from the front mid lidar.
bool optimized_car_forward(const double mid_lidar_info);

//Handles the tilt to pull off when the car meets a bent wall.
bool handle_direction(char **parsed_lidar_info,
                        const double mid_liddar_info);

#endif /* AI_H_ */