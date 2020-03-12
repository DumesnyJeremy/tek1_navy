/*
** EPITECH PROJECT, 2019
** my_getnbr_base
** File description:
** my_getnbr_base
*/

#include <my_lib_define.h>
#include <stdio.h>

int negative_count(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' && IS_PNS(str[i]); i++)
        if (str[i] == '-')
            count++;
    return (count);
}

int my_strlen_base(char const *str[], int *nbr_len, int *b, int *count)
{
    int j;
    int i;

    for (i = 0; str[0][i] != '\0'; i++) {
        if (i > 0 && (str[0][i] == '-' || str[0][i] == '+')
        && (str[0][i - 1] != '-' && str[0][i - 1] != '+'))
            return (-1);
        if (str[0][i] == '-' || str[0][i] == '+') {
            continue;
            i++;
        }
        for (j = 0; str[1][j] != '\0' && str[1][j] != str[0][i]; j++);
        if (str[1][j] == '\0')
            return (-1);
        *nbr_len += 1;
    }
    for (; str[1][*b] != '\0'; *b += 1);
    *count = negative_count(str[0]);
    return (0);
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    return (p > 1 ? nb * my_compute_power_rec(nb, p - 1) : nb);
}

int my_getnbr_base(char const *str, char const *base)
{
    int count = 0;
    int nbr_len = -1;
    int base_len = 0;
    int nbr = 0;
    int j = 0;
    char const *s[] = {str, base, NULL};

    if (my_strlen_base(s, &nbr_len, &base_len, &count) == -1)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' || str[i] == '+')
        continue;
        for (j = 0; base[j] != '\0' && base[j] != str[i]; j++);
        nbr += j * my_compute_power_rec(base_len, nbr_len);
        nbr_len--;
    }
    if (count % 2 == 1)
        nbr *= -1;
    return (nbr);
}