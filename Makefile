##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	matchstick.c		\
		create_map.c		\
		create_tab.c		\
		my_getnbr.c			\
		my_putchar.c		\
		my_putstr.c			\
		my_getnbr_oneline.c	\
		player.c			\
		error.c				\
		my_strlen.c			\
		my_str_isnum.c		\
		game.c				\
		ia.c				\
		my_putnbr.c			\
		recap_turn.c

OBJ = $(SRC:.c=.o)

NAME = matchstick

CFLAGS = -g3 -Wall -Wextra

all: $(NAME)

$(NAME):   $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
