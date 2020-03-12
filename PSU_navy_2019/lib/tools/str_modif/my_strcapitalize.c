/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalize start word
*/

#include <my_tools.h>

char *my_strlowcases(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return (str);
}

char *my_strcapitalize(char *str)
{
    str = my_strlowcases(str);

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 0; str[i] != '\0'; i++)
        if (i > 0 && str[i - 1] == '-' || str[i - 1] == '+'
        || str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}
