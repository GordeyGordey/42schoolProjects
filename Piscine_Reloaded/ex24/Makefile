# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grinko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 21:06:00 by grinko            #+#    #+#              #
#    Updated: 2019/09/03 21:06:09 by grinko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_swap.c srcs/ft_strlen.c srcs/ft_strcmp.c
INCLUDES=includes
OBJECTS=ft_putchar.o ft_putstr.o ft_swap.o ft_strlen.o ft_strcmp.o
NAME=libft.a

all: lib_compile

lib_compile:
			gcc -I $(INCLUDES) -c $(SRCS)
			ar -rc $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
