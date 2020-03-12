/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** task05
*/

#include <my_lib_define.h>
#include <my_tools.h>
#include <stddef.h>

int cheak_number_line(char const *str)
{
    int num = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    for (int i = 0; IS_NUMABS(str[i]) && str[i] != '\0'; i++)
        if (IS_NUM(str[i]))
            num++;
    return (num);
}

int chack_negative(char const *str)
{
    int j = 0;
    for (int i = 0; IS_NUMABS(str[i]) && str[i] != '\0'; i++)
        if (str[i] == '-')
            j++;
    return (j % 2);
}

int my_getnbr(char const *str)
{
    int change = 0;

    if (str == NULL || str[0] == '\0') return 0;
    if (cheak_number_line(str) > 10)
        return (0);
    for (int i = 0; IS_NUMABS(str[i]); i++) {
        if (my_char_isnum(str[i])) {
            if (chack_negative(str) == 0 && change >= 214748364 &&
                str[i] != '\0' && str[i] - '0'  > 7)
                return (0);
            else if (chack_negative(str) == 1 && change >= 214748364
            && str[i] != '\0' && str[i] - '0'  > 8)
                return (0);
            change = change * 10 + str[i] - '0';
        }
    }
    for (int i = 0; IS_NUMABS(str[i]) && str[i] != '\0'; i++)
        if (str[i] == '-')
            change = change * -1;
    return (change);
}
