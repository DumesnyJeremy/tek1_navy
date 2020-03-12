/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compre the strings
*/

#include <unistd.h>
#include <stddef.h>
#include <my_tools.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    if (s1 == NULL || s2 == NULL) {
        write(2, "s1 or s2 is NULL\n", 18);
        return 0;
    }
    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else
        return (s1[i] - s2[i]);
}

int my_strcmp2(char const *s1, char const *s2)
{
    int i;

    if (s1 == NULL || s2 == NULL)
        return -1;
    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else
        return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return (0);
    for (; s1[i] == s2[i] && s1[i] != '\0' && i < n - 1; i++);
    return (s1[i] - s2[i]);
}

bool my_strcmptab(char **tab, char *src)
{
    int i = 0;
    for (; tab[i] != NULL && my_strcmp(src, tab[i]) != 0; i++);
    if (tab[i] == NULL)
        return true;
    else
        return false;
}