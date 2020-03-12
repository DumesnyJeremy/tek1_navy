/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <my_tools.h>

char *my_strdup(char const *src)
{
    if (src == NULL)
        return NULL;
    int nb_len = my_strlen(src) + 1;
    char *cpy = malloc(sizeof(char) * (nb_len));

    if (cpy == NULL)
        return (NULL);
    cpy = my_strcpy(cpy, src);
    return (cpy);
}

char *my_strndup(char const *str, int size)
{
    char *cpy = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return (NULL);
    cpy = my_strncpy(cpy, str, size);
    return (cpy);
}

char *my_strncdup(char *dest, char const *str, int n)
{
    int len = 0, i = 0;

    if (n < my_strlen(str) && n >= 0)
        len = my_strlen(dest) + n;
    else
        len = my_strlen(dest) + my_strlen(str);
    char *src = malloc(sizeof(char) * (len + 1));
    if (dest != NULL && dest[0] != '\0') {
        for (; dest[i] != '\0'; i++)
            src[i] = dest[i];
        free(dest);
    }
    for (int j = 0; str[j] != '\0' && j < n; j++, i++) {
        src[i] = str[j];
    }
    src[i] = '\0';
    return (src);
}