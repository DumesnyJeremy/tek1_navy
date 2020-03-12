/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/

#include <stddef.h>
#include <my_tools.h>

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, char const *str, int n)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; str[i] != '\0' && i < n; i++)
        dest[i] = str[i];
    for (; i < n; i++)
        dest[i] = '\0';
    dest[i] = '\0';
    return (dest);
}