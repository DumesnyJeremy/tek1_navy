/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

#ifndef READ_SIZE
#define READ_SIZE (1053)
#endif

typedef struct get_next_line {
    char *line;
    unsigned int len;
} get_next_line_t;

char *get_next_line(int fd, char c);
get_next_line_t get_strncdup(get_next_line_t data,
                            bool *state, ssize_t *ssize, char c);
get_next_line_t get_strnlen(get_next_line_t new_data,
                            char *dest, int n, char c);

#endif /* !GET_NEXT_LINE_H_ */