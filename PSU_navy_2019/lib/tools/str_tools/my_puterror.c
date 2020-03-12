/*
** EPITECH PROJECT, 2020
** PSU_minishell1
** File description:
** my_puterror
*/

#include <unistd.h>
#include <stddef.h>
#include <my_tools.h>

void putserr(char const *str)
{
    if (str != NULL && str[0] != '\0')
        write(2, str, my_strlen(str));
}