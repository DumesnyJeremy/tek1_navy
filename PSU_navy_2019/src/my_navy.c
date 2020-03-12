/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** my_navy
*/

#include <my_navy.h>
#include <my_tools.h>
#include <my_printf_tools.h>

void update_maps(data_t *src)
{
    pstr_c("my positions:\n");
    print_map(src->my_map);
    pstr_c("enemy's positions:\n");
    print_map(src->his_map);
}

int win_lose(data_t *src)
{
    if (src->my_life == 0) {
        pstr_c("Enemy won\n");
        return 0;
    } else if (src->his_life == 0) {
        pstr_c("I won\n");
        return 1;
    }
}

int navy_1(data_t *src)
{
    char *s = NULL, *t = NULL, l[8], l2[8];
    pstr_c("\nwaiting for enemy connection...\n\n");
    my_navy_signal(src);
    if (my_strcmp(src->msg, SNED_CONETION) == 0) {
        send_binary_messge(RECEED_CONECTION, src->his_pid);
        pstr_c("enemy connected\n\n");
    }
    free(src->msg);
    src->msg = NULL;
    while (src->my_life != 0 && src->his_life != 0) {
        update_maps(src);
        if (navy_attack(src) == -1) return 0;
        if (src->my_life == 0 || src->his_life == 0) break;
        navy_waiting_attack(src);
    }
    update_maps(src);
    return win_lose(src);
}

int navy_2(data_t *src)
{
    char *s = NULL, *t = NULL, l[8], l2[8];
    my_navy_signal(src);
    if (my_strcmp(src->msg, RECEED_CONECTION) == 0)
        pstr_c("\nsuccessfully connected\n\n");
    free(src->msg);
    src->msg = NULL;
    while (src->my_life != 0 && src->his_life != 0) {
        update_maps(src);
        navy_waiting_attack(src);
        if (src->my_life == 0 || src->his_life == 0) break;
        if (navy_attack(src) == -1) return 0;
    }
    update_maps(src);
    return win_lose(src);
}