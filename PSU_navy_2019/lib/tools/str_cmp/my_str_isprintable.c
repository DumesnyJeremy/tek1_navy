/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** my_str_isprintable
*/

#include <stddef.h>
#include <stdbool.h>

bool my_char_isprintable(char c)
{
    if (c >= 32 && c <= 126)
        return true;
    else
        return false;
}

bool my_str_isprintable(char const *str)
{
    int i;

    if ( str == NULL)
        return false;
    if (str[0] == '\0')
        return true;
    for (i = 0; str[i] != '\0' && my_char_isprintable(str[i]) == 1; i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}
