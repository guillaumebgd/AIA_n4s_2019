/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Tests whether the track is cleared or not.
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(is_track_cleared, finds_out_track_is_cleared)
{
    char output[] = "1:OK:Track Cleared:No further information.";

    cr_assert_eq(is_track_cleared(output, false), true);
}

Test(is_track_cleared, finds_out_track_isnt_cleared)
{
    char output[] = "1:OK:Checkpoint passed:No further information.";

    cr_assert_eq(is_track_cleared(output, false), false);
}