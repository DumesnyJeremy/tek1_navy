/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** swap in int
*/

#include <my_tools.h>

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
