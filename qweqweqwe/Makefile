# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grinko <grinko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 18:34:06 by grinko            #+#    #+#              #
#    Updated: 2019/11/27 17:36:39 by grinko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/checkall.c srcs/fillit.c srcs/mapochki.c srcs/stack_f.c srcs/t_tetr.c srcs/viktor.c srcs/find.c
INC = srcs/fillit.h
OBJS = srcs/checkall.o srcs/fillit.o srcs/mapochki.o srcs/stack_f.o srcs/t_tetr.o srcs/viktor.o srcs/find.o
LIB = libft/
LIBA = libft/libft.a

all: $(NAME)

$(OBJS): %.o: %.c
	gcc -c -g $(FLAGS) $< -o $@

$(LIBA):
	make -C $(LIB)

$(NAME): $(LIBA) $(OBJS)
	gcc -g $(FLAGS) $(OBJS) -L $(LIB) -lft -o $(NAME)
	
clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all
.PHONY : all clean fclean re