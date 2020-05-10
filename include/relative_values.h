/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Arrays of matching values between given distances and actions.
*/

#ifndef RELATIVE_VALUES_H_
#define RELATIVE_VALUES_H_

static const double speed_milestones[] = {
    2000,
    1500,
    1000,
    600,
    400,
};

static const double rotation_milestones[] = {
    1500,
    1000,
    600,
    400,
    200,
};

////////////////////////////////////////////////

#define NB_SPEED_MILESTONES (5)
#define NB_ROTATION_MILESTONES (5)

#define DEFAULT_SPEED "CAR_FORWARD:0.1\n"
#define DEFAULT_ROTATION "0.5\n"

////////////////////////////////////////////////

static const char *speed_forward[] = {
    "CAR_FORWARD:1.0\n",
    "CAR_FORWARD:0.8\n",
    "CAR_FORWARD:0.5\n",
    "CAR_FORWARD:0.4\n",
    "CAR_FORWARD:0.2\n",
};

static const char *rotate_sideways[] = {
    "0.005\n",
    "0.05\n",
    "0.1\n",
    "0.2\n",
    "0.3\n",
};

#endif /* RELATIVE_VALUES_H_ */