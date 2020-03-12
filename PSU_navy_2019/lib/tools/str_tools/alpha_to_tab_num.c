/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** alpha_to_tab_num
*/

int alpha_to_tab_num(char *src, char c)
{
    int i = 0;
    for (; src[i] != '\0' && src[i] != c; i++);
    if (src[i] == '\0')
        return -1;
    else
        return i;
}