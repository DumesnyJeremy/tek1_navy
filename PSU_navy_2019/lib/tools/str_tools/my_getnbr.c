/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** task05
*/

#include <stdlib.h>
#include <my_lib_define.h>
#include <my_tools.h>

int cheak_number_line_p(char const *str)
{
    int num = 0;
    for (int i = 0; my_char_isnum(str[i]) && str[i] != '\0' ||
        IS_PNS(str[i]); i++)
        if (my_char_isnum(str[i]))
            num++;
    return (num);
}

int check_negative(char const *str)
{
    int j = 0;
    int i = 0;

    for (; IS_PNS(str[i]) && str[i] != '\0' && my_char_isnum(str[i]) != 1; i++)
        if (str[i] == '-')
            j++;
    return (str[i] == '\0' || my_char_isnum(str[i]) ? -1 : j % 2);
}

int my_getnbr_to_int(char const *str)
{
    int change = 0;

    if (cheak_number_line_p(str) > 10)
        return (0);
    for (int i = 0; (my_char_isnum(str[i])) ||
    (str[i] == '-') || (str[i] == '+'); i++) {
        if (my_char_isnum(str[i])) {
            if (check_negative(str) == 0 && change >= 214748364 &&
                str[i] != '\0' && str[i] - '0'  > 7)
                return (0);
            else if (check_negative(str) == 1 && change >= 214748364
            && str[i] != '\0' && str[i] - '0'  > 8)
                return (0);
            change = change * 10 + str[i] - '0';
        }
    }
    if (check_negative(str) == 1)
        change = change * -1;
    return (change);
}

char *my_getnbr_to_str(char const *str)
{
    int j = 0;
    char *change = malloc(sizeof(char) * my_strlen(str) + 2);

    if (check_negative(str) == -1)
    return (NULL);
    if (check_negative(str) == 1)
        change[j++] = '-';
    for (int i = 0; str[i] != '\0' && IS_NUMABS(str[i]) == 1; i++) {
        if (i > 0 && IS_PNS(str[i]) && my_char_isnum(str[i - 1]) == 1) {
            return (change);
        }
        if (my_char_isnum(str[i]) == 1) {
            change[j++] = str[i];
            change[j] = '\0';
        }
    }
    change[j] = '\0';
    return (change);
}