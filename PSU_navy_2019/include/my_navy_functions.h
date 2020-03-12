/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_navy_functions
*/

#pragma once

// this function is in "my_navy_map.c"\\
// creat navy the map
void set_basic_map(map_t *map);
// this function is in "my_navy_map.c"\\
// print navy map
void print_map(map_t *map);
// this function is in "my_navy_map.c"\\
// open navy position file and check file errors;
char *open_navy_position_file(char *buf, char const *file_name);
// this function is in "my_navy_map.c"\\
// set navy position forme file;
int set_navy_position(map_t *map, char *navy_pos);

void sig_op(int signo, siginfo_t *info, void *context);
void set_signal(void);

// this function is in "my_navy_signal.c"\\
// reseve a signal messge;
int my_navy_signal(data_t *src);

// this function is in "my_navy_signal.c"\\
// sendd binar messge;
int send_binary_messge(char *messge, pid_t pid);

// this function is in "my_navy.c"\\
// use in conditon is fist player;
int navy_1(data_t *src);
// this function is in "my_navy.c"\\
// use in conditon is second player;
int navy_2(data_t *src);

// this function is in "my_navy_uitl.c"\\
// cheak_error_inuput_case;
int available(char **s, data_t *src);

// this function is in "my_navy_uitl.c"\\
// use when palyer be attact postion;
int navy_attack(data_t *src);

// this function is in "my_navy_uitl.c"\\
// use when palyer waiting for enamy attac;
void navy_waiting_attack(data_t *src);

// this function is in "my_navy_uitl.c"\\
// use when modifi_map;
char *modifi_map(char *map_line, char *life, bool is_touched);

// this function is in "my_navy_uitl.c"\\
// use for cheak plyaer hit on nvay or not return hit or missed and modiff map;
char *check_hit_miss(data_t *src, bool is_eneimy, char *pos);
// this function is in "my_navy.c"\\
// check who win who lose the game;
int win_lose(data_t *src);
