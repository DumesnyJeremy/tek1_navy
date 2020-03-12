/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_navy_main
*/

#include <my_navy.h>
#include <my_tools.h>
#include <my_printf.h>
#include <my_printf_tools.h>

void navy_usage(void)
{
    int fd = open(".USAGE.txt", O_RDONLY);
    char buf[201];
    read(fd, buf, 200);
    close(fd);
    buf[200] = '\n';
    buf[201] = '\0';
    pstr_c(buf);
}

int ceat_my_map(data_t *data, char const *navy_pos_file)
{
    char buf[31];

    data->my_pid = getpid();
    set_basic_map(data->my_map);
    set_basic_map(data->his_map);
    data->his_life = 14;
    data->my_life = 14;
    if (open_navy_position_file(buf, navy_pos_file) == NULL)
        return 84;
    if (set_navy_position(data->my_map, buf) == 84)
        return 84;
    write(1, "my_pid: ", 8);
    nbr_i(data->my_pid);
    //my_printf("my_pid: %d", data->my_pid);
    return 0;
}

void set_signal(void)
{
    struct sigaction act, oact;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = sig_op;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &act, &oact) == -1)
        pstr_c("SIGUSR1, install error~!\n");
    if (sigaction(SIGUSR2, &act, &oact) == -1)
        pstr_c("SIGUSR1, install error~!\n");
}

int main(int ac, char const *av[])
{
    set_signal();
    if (ac == 2 && my_strcmp("-h", av[1]) == 0) {
        navy_usage();
        return 0;
    }
    data_t *data = malloc(sizeof(data_t));
    data->msg = NULL;
    if (ac == 2) {
        if (ceat_my_map(data, av[1]) == 84) return 84;
        navy_1(data);
    } else if (ac == 3) {
        if (ceat_my_map(data, av[2]) == 84) return 84;
        data->his_pid = my_getnbr_to_int(av[1]);
        send_binary_messge(SNED_CONETION, data->his_pid);
        navy_2(data);
    }
    free(data);
    return 0;
}
