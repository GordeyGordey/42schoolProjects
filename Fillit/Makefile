# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grinko <grinko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 18:34:06 by grinko            #+#    #+#              #
#    Updated: 2019/11/19 17:43:53 by grinko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/*.c
INC = srcs/fillit.h
OBJS = ./srcs/*.o
LIB = libft/

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INC) -L $(LIB) -lft

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all