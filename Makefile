# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnxele <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 22:07:23 by vnxele            #+#    #+#              #
#    Updated: 2017/11/30 11:41:32 by vnxele           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c

NAME = lem-in

LIB = -L libft -lft

FLAGS = -Wall -Werror -Wextra

SRC = lem_in.c farm.c store.c check.c insert.c path.c ant.c helpr_ft.c free.c\

OBJ = lem_in.o farm.o store.o check.o insert.o path.o ant.o helpr_ft.o free.o\

all: $(NAME)

$(NAME):
	   @make -C libft/ fclean && make -C libft/
		    @clang $(SRC) $(LIB) -o $(NAME) $(FLAGS)

clean:
	    @/bin/rm -f $(OBJ)

fclean: clean
	    @/bin/rm $(NAME)

re: fclean all
