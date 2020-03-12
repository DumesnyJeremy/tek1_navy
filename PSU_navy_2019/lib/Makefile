##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## makefile
##

SRC	+= ./double_linked_list/list_tools.c\
		./double_linked_list/pop_list.c\
		./double_linked_list/push_list.c\
		./double_linked_list/swap_list0.c\
		./double_linked_list/swap_list1.c\
		./double_linked_list/pop_list.c\

SRC	+=	./my_printf/lib/digital/put_num0.c\
		./my_printf/lib/digital/put_num1.c\
		./my_printf/lib/digital/u_put_num0.c\
		./my_printf/lib/digital/u_put_num1.c\
		./my_printf/lib/digital/u_put_num2.c\
		./my_printf/lib/digital/u_put_num3.c\
		./my_printf/lib/digital/u_put_num4.c\
		./my_printf/lib/particular/particular0.c\
		./my_printf/lib/particular/flag_option0.c\
		./my_printf/lib/particular/flag_option1.c\
		./my_printf/lib/particular/flag_option2.c\
		./my_printf/lib/string/put_str0.c\
		./my_printf/lib/string/put_str1.c\
		./my_printf/lib/type/type0.c\
		./my_printf/lib/type/type1.c\
		./my_printf/lib/type/type2.c\
		./my_printf/src/error0.c\
		./my_printf/src/flag_operation.c\
		./my_printf/src/my_getnbr.c\
		./my_printf/src/my_printf.c\
		./my_printf/src/tools0.c\
		./my_printf/src/tools1.c\
		./my_printf/src/tools2.c\

SRC +=	./tools/str_cmp/my_str_isnum.c\
		./tools/str_cmp/my_str_isalpha.c\
		./tools/str_cmp/my_str_islower.c\
		./tools/str_cmp/my_str_isupper.c\
		./tools/str_cmp/my_str_isprintable.c\
		./tools/str_cmp/my_str_isalphanumeric.c\
		./tools/str_cmp/my_strcmp.c\

SRC += ./tools/str_count/my_strlen.c\

SRC +=	./tools/str_modif/my_revstr.c\
		./tools/str_modif/my_strcapitalize.c\
		./tools/str_modif/my_strcat.c\
		./tools/str_modif/my_strcpy.c\
		./tools/str_modif/my_strlowcase.c\
		./tools/str_modif/my_strstr.c\
		./tools/str_modif/my_swap.c\

SRC +=	./tools/str_tools/alpha_to_tab_num.c\
		./tools/str_tools/my_getnbr_base.c\
		./tools/str_tools/my_getenv.c\
		./tools/str_tools/my_getnbr.c\
		./tools/str_tools/my_puterror.c\
		./tools/str_tools/my_putnbr_base.c\
		./tools/str_tools/my_str_to_word_array.c\
		./tools/str_tools/my_strdup.c\
		./tools/str_tools/my_show_word_array.c\
		./tools/str_tools/get_next_line.c\

NAME	=	libmy_tools.a

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

CFLAGS	=	-g -g3 -I../include/lib_inc/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf  $(OBJ)
	rm -f	*~
	rm -f	*#
	rm -f	#*

fclean:	clean
	rm -rf  $(NAME)

re:	fclean all