/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf.c
*/

#include <my_tools.h>
#include <my_printf_tools.h>

char *bnm_cul_l(long nbr, char const *base, int len, char **stock)
{
    if (nbr >= len) {
        bnm_cul_l(nbr / len, base, len, stock);
        bnm_cul_l(nbr % len, base, len, stock);
    } else
        *stock = my_strncdup(*stock, &base[nbr], 1);
}

char *bnm_l(long nbr, char const *base)
{
    int i;
    char *stock = NULL;

    if (nbr == INT_LEAST64_MIN)
        return ("-9223372036854775808");
    if (nbr < 0) {
        nbr = nbr * -1;
    }
    for (i = 0; base[i] != '\0'; i++);
    bnm_cul_l(nbr, base, i, &stock);
    return (stock);
}