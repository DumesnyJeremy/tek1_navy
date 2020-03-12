/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** creat_map
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <my_navy.h>
#include <my_tools.h>
#include <my_printf.h>
#include <my_printf_tools.h>

void set_basic_map(map_t *map)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            map[i].line[j].c = '.';
            map[i].line[j].bl = false;
        }
}

int set_navy_position(map_t *map, char *navy_pos)
{
    char c = '2', s[] = "ABCDEFGH";

    for (int i = 0; i < 32; i += 8, c++) {
        if (navy_pos[i + 2] == navy_pos[i + 5])
            for (int j = 0; j <= navy_pos[i + 6] - navy_pos[i + 3]; j++)
                if (map[navy_pos[i + 3] - 48 + j - 1].line[
                    alpha_to_tab_num(s, navy_pos[i + 2])].c != '.')
                    return 84;
                else
                    map[navy_pos[i + 3] - 48 + j - 1].line[
                        alpha_to_tab_num(s, navy_pos[i + 2])].c = c;
        else if (navy_pos[i + 3] == navy_pos[i + 6])
            for (int j = 0; j <= navy_pos[i + 5] - navy_pos[i + 2]; j++)
                if (map[navy_pos[i + 3] - 48 - 1].line[
                    alpha_to_tab_num(s, navy_pos[i + 2]) + j].c != '.')
                    return 84;
                else
                    map[navy_pos[i + 3] - 48 - 1].line[
                        alpha_to_tab_num(s, navy_pos[i + 2]) + j].c = c;
    }
}

void print_map(map_t *map)
{
    pstr_c(" |A B C D E F G H\n"
            "-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++)
            if (j < 7)
                my_printf("%c ", map[i].line[j].c);
            else
                my_printf("%c\n", map[i].line[j].c);
    }
    pstr_c("\n");
}

int check_navy_position_file_errors(char *buf)
{
    char line_num = '2', max = 2, x;
    #define MAX_LINE_NUM(C) (C >= '1' && C <= '8')
    #define IS_NOT_CHAR(C) (C != 'A' && C != 'B' && C != 'C' && C != 'D' && \
        C != 'E' && C != 'F' && C != 'G' && C != 'H')

    for (int i = 0; i < 32; i += 8, line_num++) {
        if (buf[i] != line_num || buf[i + 1] != ':' || buf[i + 4] != ':')
            return 84;
        if (IS_NOT_CHAR(buf[i + 2]) || IS_NOT_CHAR(buf[i + 5]) ||
            !MAX_LINE_NUM(buf[i + 3]) || !MAX_LINE_NUM(buf[i + 6]))
            return 84;
        if (buf[i + 2] > buf[i + 5] || buf[i + 3] > buf[i + 6]) return 84;
        if ((buf[i + 2] == buf[i + 5] && buf[i + 3] == buf[i + 6]) ||
            (buf[i + 2] != buf[i + 5] && buf[i + 3] != buf[i + 6]))
            return 84;
        if ((x = ABS(buf[i + 2] - buf[i + 5])), x != line_num - 1 && x != 0 &&
            (x = ABS(buf[i + 3] - buf[i + 6])), x != line_num - 1 && x != 0)
                return 84;
    }
    return 0;
}

char *open_navy_position_file(char *buf, char const *file_name)
{
    int fd  = 0;
    ssize_t ssize;

    if ((fd = open(file_name, O_RDONLY)) < 0)
        return NULL;
    if ((ssize = read(fd, buf, 31)), ssize == 0 || ssize < 0)
        return NULL;
    if (read(fd, buf, 1) != 0)
        return NULL;
    close(fd);
    buf[31] = '\0';
    if (check_navy_position_file_errors(buf) == 84)
        return NULL;
    return buf;
}