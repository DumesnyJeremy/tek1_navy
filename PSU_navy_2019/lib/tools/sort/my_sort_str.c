/*
** EPITECH PROJECT, 2019
** sort
** File description:
** sort
*/

void my_swap_str(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}