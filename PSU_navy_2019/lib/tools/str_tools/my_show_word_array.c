/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** my_show_word_array
*/

#include <my_printf_tools.h>

void my_show_word_array(char * const *top)
{
    for (int i = 0; top[i] != NULL; i++) {
        pstr_c(top[i]);
        write(1, "\n", 1);
    }
}
