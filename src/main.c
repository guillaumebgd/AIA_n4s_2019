/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Main function of the ai program.
*/

#include "ai.h"

int main(const int ac, const char **av)
{
    if (ac <= 0 || !av)
        return (84);
    execute_command("START_SIMULATION\n");
    execute_simulation();
    execute_command("STOP_SIMULATION\n");
    return (0);
}