/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** my_str_isalpha
*/

#include <stddef.h>
#include <stdbool.h>

bool my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}

bool my_str_isalpha(char const *str)
{
    int i;

    if ( str == NULL)
        return false;
    if (str[0] == '\0')
        return true;
    for (i = 0; str[i] != '\0' && my_char_isalpha(str[i]) == 1; i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}
