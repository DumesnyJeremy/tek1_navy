/*
** EPITECH PROJECT, 2020
** PSU_matchstick1_2019
** File description:
** my_strlen
*/

#include <stdio.h>
#include <stddef.h>
#include <my_tools.h>

unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;
    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}

unsigned int my_strlentab(char  **tab)
{
    unsigned int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}


unsigned int my_strnlen(char const *str, char *the_end, bool is_words)
{
    unsigned int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0' &&
        my_strstr_bool(&str[i], the_end, is_words) != 0; i++);
    return i;
}