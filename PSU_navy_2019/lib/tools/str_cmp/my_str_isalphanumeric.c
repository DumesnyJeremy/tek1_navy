/*
** EPITECH PROJECT, 2019
** my_str_islphanumeric
** File description:
** check str and char is num or alpha
*/

#include <stdbool.h>
#include <stddef.h>

bool my_char_isalphanumeric(char c)
{
    if (c >= 'a' && c <= 'z' ||
        c >= 'A' && c <= 'Z' ||
        c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool my_str_isalphanumeric(char const *str)
{
    int i;

    if (str == NULL)
        return false;
    if (str[0] == '\0')
        return true;
    for (i = 0; str[i] != '\0' && my_char_isalphanumeric(str[i]); i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}

bool my_char_isalphanumerics(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '_')
        return true;
    else
        return false;
}

bool my_str_isalphanumerics(char const *str)
{
    int i;

    if (str == NULL)
        return false;
    if (str[0] == '\0')
        return true;
    for (i = 0; str[i] != '\0' && my_char_isalphanumerics(str[i]); i++);
    if (str[i] == '\0')
        return true;
    else
        return false;
}