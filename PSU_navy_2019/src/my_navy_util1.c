/*
** EPITECH PROJECT, 2020
** navy
** File description:
** my_navy1
*/

#include <my_navy.h>
#include <my_tools.h>
#include <my_printf.h>
#include <get_next_line.h>
#include <my_printf_tools.h>

int available(char **s, data_t *src)
{
    if (*s == NULL) return -1;
    if (!((*s)[0] >= 'A' && (*s)[0] <= 'H' &&
        (*s)[1] >= '1' && (*s)[1] <= '8' &&
        (*s)[2] == '\0')) {
        pstr_c("wrong position\n");
        pstr_c("attack:");
        if (!*s) free(*s);
        *s = NULL;
        *s = get_next_line(0, '\n');
        available(s, src);
    }
    if (*s == NULL) return -1;
    return 0;
}

int navy_attack(data_t *src)
{
    char *s = NULL, *t = NULL, l1[8], l2[8];

    pstr_c("attack: ");
    s = get_next_line(0, '\n');
    if (available(&s, src) == -1) return -1;
    s = my_strncdup(s, " END", 4);
    send_binary_messge(s, src->his_pid);
    my_navy_signal(src);
    my_strncpy(l1, src->msg, my_strlen(src->msg) - 4);
    my_strncpy(l2, s, my_strlen(s) - 4);
    t = check_hit_miss(src, true, s);
    my_printf("%s: %s\n\n", l2, l1);
    if (src->msg != NULL) free(src->msg);
    src->msg = NULL;
    free(s);
    free(t);
}

void navy_waiting_attack(data_t *src)
{
    char *t = NULL, l1[8];

    pstr_c("waiting for enemy's attack...\n");
    my_navy_signal(src);
    my_strncpy(l1, src->msg, 2);
    t = check_hit_miss(src, false, src->msg);
    my_printf("%s: %s\n\n", l1, t);
    t = my_strncdup(t, " END", 4);
    send_binary_messge(t, src->his_pid);
    if (src->msg != NULL) free(src->msg);
    src->msg = NULL;
    free(t);
}

char *modifi_map(char *map_line, char *life, bool is_touched)
{
    if (is_touched) {
        *map_line = 'x';
        *life -= 1;
        return my_strdup("hit");
    } else {
        *map_line = 'o';
        return my_strdup("missed");
    }
}

char *check_hit_miss(data_t *src, bool is_eneimy, char *pos)
{
    int w = alpha_to_tab_num("ABCDEFGH", pos[0]), h = my_getnbr(&pos[1]) - 1;

    if (!is_eneimy)
        if (src->my_map[h].line[w].c == '.')
            return modifi_map(&src->my_map[h].line[w].c, &src->my_life, false);
        else
            return modifi_map(&src->my_map[h].line[w].c, &src->my_life, true);
    else if (is_eneimy)
        if (my_strcmp(src->msg, "hit END") == 0)
            return modifi_map(&src->his_map[h].line[w].c, &src->his_life, true);
        else
            return modifi_map(&src->his_map[h].line[w].c, &src->his_life,
                                                                    false);
}