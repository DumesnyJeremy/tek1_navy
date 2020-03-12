/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** str str
*/

#include <stddef.h>
#include <my_tools.h>

char *my_strstr(char *str, char const *to_find)
{
    int b = 0, j = 0;

    for (int i = 0; str[i] != '\0'; i++, b = i)
        if (str[i] == to_find[0]) {
            for (j = 0; to_find[j] != '\0' && to_find[j] == str[b]; b++, j++);
            if (to_find[j] == '\0')
                return &str[b];
        }
    return str;
}

bool my_strstr_bool(char const *str, char const *to_find, bool is_words)
{
    int b = 0, j = 0;
    #define NL(C) (C >= 0 || C <= 32)

    if (str == NULL || to_find == NULL) return false;
    for (int i = 0; str[i] != '\0'; i++, b = i) {
        if (str[i] == to_find[0] && is_words == false) {
            for (j = 0; to_find[j] != '\0' && to_find[j] == str[b]; b++, j++);
            if (to_find[j] == '\0')
                return true;
        } else if (str[i] == ' ' && str[i + 1] == to_find[0]) {
            for (j = 0; to_find[j] != '\0' && str[b + 1] != '\0' &&
                to_find[j] == str[b + 1]; b++, j++);
            if (to_find[j] == '\0' && NL(str[b + 1]))
                return true;
        }
    }
    return false;
}