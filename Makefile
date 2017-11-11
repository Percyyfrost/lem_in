# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnxele <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 22:07:23 by vnxele            #+#    #+#              #
#    Updated: 2017/11/11 09:43:44 by vnxele           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c

NAME = Lem_in

LIB = -L libft -lft

FLAGS = -Wall -Werror -Wextra

SRC = lem_in.c farm.c parth.c store.c\

OBJ = lem_in.o farm.o parth.o store.o\

all: $(NAME)

$(NAME):
	    make -C libft/ fclean && make -C libft/
		    clang $(SRC) $(LIB) -o $(NAME)

clean:
	    /bin/rm -f $(OBJ)

fclean: clean
	    /bin/rm $(NAME)

re: fclean all
