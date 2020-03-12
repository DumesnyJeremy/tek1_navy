/*
** EPITECH PROJECT, 2019
** my_sort_int_array.c
** File description:
** sort int array
*/

#include <my_tools.h>

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (array[j] > array[i])
                swap_int(&array[j], &array[i]);
}
