# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnxele <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 22:07:23 by vnxele            #+#    #+#              #
#    Updated: 2017/11/03 14:39:09 by vnxele           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c

NAME = Lem_in

LIB = -L libft -lft

FLAGS = -Wall -Werror -Wextra

SRC = lem_in.c farm.c get_distance.c\

OBJ = lem_in.o farm.o get_distance.o\

all: $(NAME)

$(NAME):
	    make -C libft/ fclean && make -C libft/
		    clang $(SRC) $(LIB) -o $(NAME)

clean:
	    /bin/rm -f $(OBJ)

fclean: clean
	    /bin/rm $(NAME)

re: fclean all
