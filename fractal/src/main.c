/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:31 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 16:03:55 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		select_fractal(char **argv, t_fractal *fraki)
{
	if (ft_strcmp(argv[1], "julia") == 0)
		fraki->fractal = 0;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fraki->fractal = 1;
	else if (ft_strcmp(argv[1], "mandelbar") == 0)
		fraki->fractal = 2;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		fraki->fractal = 3;
	else if (ft_strcmp(argv[1], "palmset") == 0)
		fraki->fractal = 4;
	else
		disiserrorbitch(ARGER);
	return (1);
}

void	makimaki(t_fractal *fraki)
{
	fraki->por = 0;
	if (fraki->fractal == 0)
		julia(fraki);
	if (fraki->fractal == 1)
		mandelbrot(fraki);
	if (fraki->fractal == 2)
		mandelbar(fraki);
	if (fraki->fractal == 3)
		burningship(fraki);
	if (fraki->fractal == 4)
		palmset(fraki);
	mlx_put_image_to_window(fraki->init, fraki->win, fraki->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_fractal	*fraki;

	if (!(fraki = (t_fractal *)malloc(sizeof(t_fractal))))
		disiserrorbitch("Error");
	if (argc == 2)
	{
		initall(fraki, argv);
		makimaki(fraki);
		mlx_put_image_to_window(fraki->init, fraki->win, fraki->img, 0, 0);
	}
	else
		disiserrorbitch("Too many arguments or no arguments");
	mlx_hook(fraki->win, 6, 0, julia_motion, fraki);
	mlx_loop(fraki->init);
	return (0);
}
