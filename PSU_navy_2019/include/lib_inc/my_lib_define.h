/*
** EPITECH PROJECT, 2020
** PSU_matchstick1_2019
** File description:
** my_lib_inc_define
*/

#ifndef MY_LIB_INC_DEFINE_H_
#define MY_LIB_INC_DEFINE_H_

#define IS_PNS(c) (c == '+' || c == '-')
#define ABS(value) ((value < 0) ? ((value) * -1) : (value))
#define IS_NUM(c) (c >= '1' && c <= '9')
#define IS_NUMABS(c) ((c >= '0' && c <= '9') || c == '-' || c == '+')

#endif /* !MY_LIB_INC_DEFINE_H_ */
