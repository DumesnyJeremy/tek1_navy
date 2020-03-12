/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/

#include <stddef.h>
#include <stdbool.h>

bool my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool my_str_isnum(char const *str)
{
    int i;

    if ( str == NULL)
        return false;
    if (str[0] == '\0')
        return true;
    for (i = 0; str[i] != '\0' && my_char_isnum(str[i]) == 1; i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}
