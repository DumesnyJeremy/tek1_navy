/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_navy_signal
*/

#include <my_navy.h>
#include <my_tools.h>
#include <my_printf.h>
#include <my_printf_tools.h>

buf_t buf;

void sig_op(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1) {
        my_strcat(buf.msg, "0");
    } else if (signo == SIGUSR2) {
        my_strcat(buf.msg, "1");
    }
    buf.pid = info->si_pid;
}

int my_navy_signal(data_t *src)
{
    if (buf.msg[0] != '0' && buf.msg[0] != '1')
        buf.msg[0] = '\0';

    while (!my_strstr_bool(src->msg, "END", true)) {
        if (my_strlen(buf.msg) == 8) {
            char s = my_getnbr_base(buf.msg, "01");
            buf.msg[0] = '\0';
            src->msg = my_strncdup(src->msg, &s, 1);
        }
    }
    src->his_pid = buf.pid;
    return 0;
}

char *char_to_binary(char *dest, char c)
{
    char *tmp = bnm_l(c, "01");
    int ln_t = my_strlen(tmp), ln_d = my_strlen(dest);
    for (int i = 0; i < ln_t; i++)
        dest[ln_d - ln_t + i] = tmp[i];
    free(tmp);
    return dest;
}

int send_binary_messge(char *messge, pid_t pid)
{
    for (int i = 0; messge[i] != '\0'; i++) {
        char num[] = "00000000";
        char_to_binary(num, messge[i]);
        for (int i = 0; num[i] != '\0'; i++) {
            if (num[i] == '0')
                kill(pid, SIGUSR1);
            else if (num[i] == '1')
                kill(pid, SIGUSR2);
            usleep(200);
        }
    }
}