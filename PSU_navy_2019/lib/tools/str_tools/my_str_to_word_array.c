/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <my_tools.h>

int count_word_len(char const *str, int (*to_remove)(char const *c), int *t)
{
    int i = 0;
    for (i; str[i] != '\0' && (*t = to_remove(&str[i])) == 0; i++);
    return i;
}

int count_word(char const *str, int (*to_remove)(char const *c), int *i)
{
    int rows = 1, t = 0;

    for (int j = -1; str[*i] != '\0' && (j != 0);) {
        j = to_remove(&str[*i]);
        *i += j;
    }
    for (int s = *i; str[s] != '\0';) {
        if ((t = to_remove(&str[s])) > 0) {
            s += t;
            if (str[s] != '\0' && (t = to_remove(&str[s])) == 0)
                rows++;
        } else
            s++;
    }
    return (rows);
}

char **my_str_to_word_array(char const *str, int (*to_remove)(char const *c))
{
    if (str == NULL) return NULL;

    int i = 0, len = 0, t =  0;
    int h = 0;
    char **tab = malloc(sizeof(char *) * (count_word(str, to_remove, &i) + 1));

    for (h = 0; str[i] != '\0'; i += len + t) {
        len = count_word_len(&str[i], to_remove, &t);
        if (len > 0) {
            tab[h] = NULL;
            tab[h++] = my_strncdup(tab[h], &str[i], len);
        }
    }
    tab[h] = NULL;
    return tab;
}