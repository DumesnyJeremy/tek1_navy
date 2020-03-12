/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** my_putnbr_base
*/

#include <unistd.h>

void my_putnbr_base_cul(int nbr, char const *base, int len)
{
    if (nbr >= len) {
        my_putnbr_base_cul(nbr / len, base, len);
        my_putnbr_base_cul(nbr % len, base, len);
    } else
        write (1, &base[nbr], 1);
}

int my_putnbr_base(int nbr, char const *base)
{
    int i;

    if (nbr < 0) {
        nbr * -1;
        write(1, "-", 1);
    }
    for (i = 0; base[i] != '\0'; i++);
    my_putnbr_base_cul(nbr, base, i);
    return (0);
}
