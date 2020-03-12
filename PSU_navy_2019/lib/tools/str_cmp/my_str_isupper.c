/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** my_str_isupper
*/

#include <stddef.h>
#include <stdbool.h>

bool my_char_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

bool my_str_isupper(char const *str)
{
    int i;

    if (str == NULL)
        return false;
    if (str[0] == '\0')
        return true;
    for (i = 0; str[i] != '\0' && my_char_isupper(str[i] == 1); i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}
