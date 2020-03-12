/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_getenv.c
*/

#include <stddef.h>
#include <my_tools.h>

char *my_getenv(char const *path, char **env)
{
    int i = 0, j = 0, len = my_strlen(path);
    char *src = NULL;

    if (path == NULL || env == NULL) return NULL;
    for (; env[i] != NULL && my_strncmp(path, env[i], len) != 0; i++);
    if (env[i] != NULL) {
        for (; env[i][j] != '='; j++);
            src = &env[i][j + 1];
        return (src);
    } else
        return (NULL);
}