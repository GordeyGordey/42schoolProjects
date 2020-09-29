# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grinko <grinko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 15:31:13 by grinko            #+#    #+#              #
#    Updated: 2020/03/12 15:19:32 by grinko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRCS = src/main.c src/init.c src/drawning.c src/mandelbrot.c src/julia.c src/burningship.c src/mandelbar.c src/palmset.c src/potoki.c src/hooks.c src/mousehooks.c
OBJS = src/main.o src/init.o src/drawning.o src/mandelbrot.o src/julia.o src/burningship.o src/mandelbar.o src/palmset.o src/potoki.o src/hooks.o src/mousehooks.o
LIB = libft/
LIBA = libft/libft.a

all: $(NAME)

$(OBJS): %.o: %.c
	gcc -c -g $(FLAGS) $< -o $@

$(LIBA):
	make -C $(LIB)

$(NAME): $(LIBA) $(OBJS)
	gcc $(SRCS) $(LIBA) -lmlx -framework OpenGl -framework AppKit $(FLAGS) -o $(NAME)
debug:
	gcc -g $(SRCS) $(LIBA) -lmlx -framework OpenGl -framework AppKit $(FLAGS) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all
.PHONY : all clean fclean re