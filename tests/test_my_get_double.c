/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** Tests the lib my_getdouble function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_getdouble, basic_double)
{
    const char str[] = "3.1415";
    const double expected = 3.1415;
    double result = 0;

    result = my_getdouble(str);
    cr_assert_eq(result, expected);
}

Test(my_getdouble, invalid_input)
{
    const char str[] = "Iamnotvalid";
    const double expected = 0;
    double result = 0;

    result = my_getdouble(str);
    cr_assert_eq(result, expected);
}

Test(my_getdouble, not_decimal)
{
    const char str[] = "3";
    const double expected = 3;
    double result = 0;

    result = my_getdouble(str);
    cr_assert_eq(result, expected);
}

Test(my_getdouble, end_without_decimal_precision)
{
    const char str[] = "3.";
    const double expected = 3;
    double result = 0;

    result = my_getdouble(str);
    cr_assert_eq(result, expected);
}