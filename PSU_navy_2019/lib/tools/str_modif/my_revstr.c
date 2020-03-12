/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverses string
*/

#include <my_tools.h>

void my_swapy(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int j;

    for (j = 0; str[j] != '\0'; j++);
    j--;
    for (int i = 0; i < j;) my_swapy(&str[i++], &str[j--]);
    return (str);
}
