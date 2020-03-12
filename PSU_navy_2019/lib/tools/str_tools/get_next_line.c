/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** new_get_next_line
*/

#include <get_next_line.h>
static char buf[READ_SIZE];

get_next_line_t get_strnlen(get_next_line_t new_data, char *dest, int n,
char c)
{
    new_data = (get_next_line_t){NULL, 0u};
    int l_buf = 0, l_dest = 0;

    if (n > 0)
        for (; buf[l_buf] != c && l_buf < n; l_buf++);
    if (dest != NULL && dest[0] != '\0')
        for (; dest[l_dest] != '\0' && dest[l_dest] != c; l_dest++);
    if (n > 0) {
        if (new_data.line = malloc(sizeof(char) * (l_buf + l_dest + 1)),
            new_data.line == NULL)
            return new_data;
        if (dest != NULL && dest[0] != '\0') {
            for (new_data.len = 0; dest[new_data.len] != '\0'; new_data.len++)
                new_data.line[new_data.len] = dest[new_data.len];
            free(dest);
            dest = NULL;
        }
    }
    if (dest != NULL) free(dest);
    return new_data;
}

get_next_line_t get_strncdup(get_next_line_t data, bool *state, ssize_t *ssize,
char c)
{
    int j = 0;
    get_next_line_t new_data = get_strnlen(new_data, data.line, *ssize, c);

    if (new_data.line != NULL) {
        for (int i = 0; i < *ssize; i++, new_data.len++) {
            new_data.line[new_data.len] = buf[i];
            if (buf[i] == c) {
                new_data.line[new_data.len] = '\0';
                for (j = 0; j < (*ssize - i - 1); j++)
                    buf[j] = buf[j + i + 1];
                *ssize = j;
                *state = true;
                return new_data;
            }
        }
        if (*ssize != 0) new_data.line[new_data.len] = '\0';
        *state = false;
    }
    return new_data;
}

char *get_next_line(int fd, char c)
{
    bool state = false;
    static ssize_t ssize = 0;
    get_next_line_t data = {NULL, 0u};

    if (fd <= -1 || READ_SIZE <= 0) return NULL;
    data = get_strncdup(data, &state, &ssize, c);
        if (state == true) return data.line;
    while ((ssize = read(fd, buf, READ_SIZE)), ssize != EOF && ssize != 0) {
        if (data = get_strncdup(data, &state, &ssize, c), data.line == NULL)
            return NULL;
        if (state == 1) return data.line;
    }
    if (ssize == 0 && data.line != NULL) return data.line;
    return NULL;
}