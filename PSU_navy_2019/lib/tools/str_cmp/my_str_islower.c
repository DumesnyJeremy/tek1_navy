/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** my_str_islower
*/

#include <stdbool.h>

bool my_char_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    else
        return false;
}

bool my_str_islower(char const *str)
{
    int i;

    if (str[0] == '\0')
        return (1);
    for (i = 0; str[i] != '\0' && my_char_islower(str[i]); i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}
