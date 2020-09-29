/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:53 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 15:09:20 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initall(t_fractal *fraki, char **argv)
{
	int i;

	if (select_fractal(argv, fraki) == 0)
		disiserrorbitch("Error");
	fraki->maxiter = 50;
	fraki->init = mlx_init();
	fraki->win = mlx_new_window(fraki->init, WIDTH, HEIGHT, "fract'ol");
	if (!(fraki->img = mlx_new_image(fraki->init, WIDTH, HEIGHT)))
		disiserrorbitch("Error");
	fraki->olya = mlx_get_data_addr(fraki->img, &(fraki->pixb),
	&(fraki->strb), &i);
	default_init(fraki);
	mlx_hook(fraki->win, 2, 0, pkey, fraki);
	mlx_hook(fraki->win, 4, 0, mclick, fraki);
}

void	default_init(t_fractal *fraki)
{
	fraki->min = init_complex(-2.0, -2.0);
	fraki->max.re = 2.0;
	fraki->max.im = fraki->min.im + (fraki->max.re - fraki->min.re) *
	HEIGHT / WIDTH;
	fraki->mudlark = init_complex((fraki->max.re - fraki->min.re) /
	(WIDTH - 1), (fraki->max.im - fraki->min.im) / (HEIGHT - 1));
	fraki->k = init_complex(-0.4, 0.6);
	fraki->xmov = WIDTH / 2 - 2 / fraki->mudlark.re;
	fraki->ymov = (WIDTH - HEIGHT) / 2;
	fraki->por = 0;
	fraki->jul = 0;
	fraki->red = 255;
	fraki->green = 150;
	fraki->blue = 150;
	fraki->tcol = 1;
}

t_c		init_complex(double re, double im)
{
	t_c	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_v2	init_v(int x, int y)
{
	t_v2 a;

	a.x = x;
	a.y = y;
	return (a);
}

void	disiserrorbitch(char *str)
{
	ft_putstr(str);
	exit(0);
}
