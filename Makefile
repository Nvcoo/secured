##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## makefile
##

.PHONY: all clean fclean re

CFLAGS = -Wall -g -I./include

SRC =	./src/handler.c \
		./src/hash.c \
		./src/my.c \
		./src/two.c \

OBJ = $(SRC:.c=.o)

NAME =	libhashtable.a

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:
		fclean all
