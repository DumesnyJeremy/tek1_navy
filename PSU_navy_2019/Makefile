##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRC	=	src/my_navy_main.c\
		src/my_navy.c\
		src/my_navy_util1.c\
		src/my_navy_map.c\
		src/my_navy_signal.c\


OBJ	= 	$(SRC:.c=.o)

LIB	=	-L./lib/ -l my_tools

CFLAGS	= 	-g -g3 -I./include -I./include/lib_inc

CC	=	gcc -o

NAME	=	navy

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/
	$(CC)	$(NAME)	$(OBJ)	$(LIB)	$(CFLAGS)

clean:
	make -C ./lib/ clean
	rm -rf	$(OBJ)
	rm -f	*~
	rm -f	*#
	rm -f	#*

fclean:	clean
	make -C ./lib/ fclean
	rm -rf  $(NAME)

re:	fclean all
