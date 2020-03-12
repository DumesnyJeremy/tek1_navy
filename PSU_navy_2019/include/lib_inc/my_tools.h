/*
** EPITECH PROJECT, 2020
** PSU_matchstick1_2019
** File description:
** my_tools
*/

#ifndef MY_TOOLS_H_
#define MY_TOOLS_H_
#include <stdbool.h>

/*list fonction to compation with string and charaters*/

bool my_char_isnum(char c);
bool my_char_isalpha(char c);
bool my_char_islower(char c);
bool my_char_isuppler(char c);
bool my_char_isprintable(char c);
bool my_char_isalphanumeric(char c);
bool my_char_isalphanumerics(char c);

bool my_str_isnum(char const *str);
bool my_str_isalpha(char const *str);
bool my_str_isalower(char const *str);
bool my_str_isuppler(char const *str);
bool my_str_isprintable(char const *str);
bool my_str_isalphanumeric(char const *str);
bool my_str_isalphanumerics(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp2(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

bool my_strstr_bool(char const *str, char const *to_find, bool with_space);


/*count strings*/
unsigned int my_strlen(char const *str);
unsigned int my_strlentab(char **tab);
unsigned int my_strnlen(char const *str, char *the_end, bool is_words);

/*toos*/
int my_getnbr_to_int(char const *str);
int my_getnbr_to_char(char const *str);
int my_getnbr_base(char const *str, char const *base);
int my_putnbr_base(int nbr, char const *base);
char *my_getenv(char const *path, char **env);
void my_show_word_array(char * const *top);

// output by fd 2
void putserr(char const *str);

int my_compute_power_rec(int nb, int p);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str, int (*to_remove)(char const *c));
void my_swap(int *a, int *b);
char *my_strcat(char *dest, char const *str);
char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *str, int n);
char *my_strncat(char *dest, char const *str, int n);

char *my_strdup(char const *src);
char *my_strndup(char const *src, int size);
char *my_strncdup(char *dest, char const *src, int n);

int alpha_to_tab_num(char *src, char c);
#endif /* !MY_TOOLS_H_ */