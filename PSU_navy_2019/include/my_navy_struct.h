/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_navy_struct
*/

#pragma once

typedef struct s_line {
    char c;
    bool bl;
} line_t;

typedef struct s_map {
    line_t line[9];
} map_t;

typedef struct s_buf
{
    char msg[9];
    pid_t pid;
} buf_t;


typedef struct my_navy_struct
{
    map_t my_map[9];
    char my_life, his_life;
    map_t his_map[9];
    pid_t my_pid, his_pid;
    char *msg;
}data_t;
