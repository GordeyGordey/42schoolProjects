/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:18 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 16:29:00 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	r(int key, t_fractal *fraki)
{
	if (key == 126)
		fraki->ymov -= 10;
	if (key == 69)
		fraki->maxiter += 1;
	if (key == 53)
		exit(0);
	if (key == 123)
		fraki->xmov -= 10;
	if (key == 124)
		fraki->xmov += 10;
	if (key == 125)
		fraki->ymov += 10;
	if (key == 83)
		fraki->fractal = 0;
	if (key == 84)
		fraki->fractal = 1;
	if (key == 85)
		fraki->fractal = 2;
	if (key == 86)
		fraki->fractal = 3;
	if (key == 87)
		fraki->fractal = 4;
}

void	rr(int key, t_fractal *fraki)
{
	if (key == 78 && fraki->maxiter > 0)
		fraki->maxiter -= 1;
	if (key == 18 && fraki->red > 0)
		fraki->red--;
	if (key == 19 && fraki->red < 255)
		fraki->red++;
	if (key == 20 && fraki->green > 0)
		fraki->green--;
	if (key == 21 && fraki->green < 255)
		fraki->green++;
	if (key == 23 && fraki->blue > 0)
		fraki->blue--;
	if (key == 22 && fraki->blue < 255)
		fraki->blue++;
	if (key == 6)
		fraki->tcol = 3;
	if (key == 7)
		fraki->tcol = 2;
	if (key == 8)
		fraki->tcol = 1;
	if (key == 9)
		fraki->tcol = 4;
	if (key == 11)
		fraki->tcol = 5;
}

void	rrr(int key, t_fractal *fraki)
{
	if (key == 45)
		helpwin(fraki);
	if (key == 27)
	{
		fraki->max.re /= 0.95;
		fraki->min.im /= 0.95;
		fraki->min.re /= 0.95;
		fraki->max.im = fraki->min.im + (fraki->max.re - fraki->min.re)
		* HEIGHT / WIDTH;
		fraki->mudlark = init_complex((fraki->max.re - fraki->min.re) /
		(WIDTH - 1), (fraki->max.im - fraki->min.im) / (HEIGHT - 1));
	}
	if (key == 24)
	{
		fraki->max.re *= 0.95;
		fraki->min.im *= 0.95;
		fraki->min.re *= 0.95;
		fraki->max.im = fraki->min.im + (fraki->max.re - fraki->min.re)
		* HEIGHT / WIDTH;
		fraki->mudlark = init_complex((fraki->max.re - fraki->min.re) /
		(WIDTH - 1), (fraki->max.im - fraki->min.im) / (HEIGHT - 1));
	}
}

int		pkey(int key, t_fractal *fraki)
{
	r(key, fraki);
	rr(key, fraki);
	rrr(key, fraki);
	makimaki(fraki);
	return (0);
}

void	helpwin(t_fractal *fraki)
{
	fraki->hinit = mlx_init();
	fraki->hwin = mlx_new_window(fraki->hinit, 450, 400, "Help");
	mlx_string_put(fraki->hinit, fraki->hwin, 170, 5, 0xDEEDD3, "NAVIGATION");
	mlx_string_put(fraki->hinit, fraki->hwin, 150, 45, 0xDEEDD3, USE);
	mlx_string_put(fraki->hinit, fraki->hwin, 60, 75, 0xDEEDD3,
	"Use + - (Npad) to change accuracy");
	mlx_string_put(fraki->hinit, fraki->hwin, 80, 105, 0xDEEDD3,
	"<- ^ -> you can move fractal");
	mlx_string_put(fraki->hinit, fraki->hwin, 65, 135, 0xDEEDD3,
	"Chose 5 fractals on Npad (1,2,3,4,5)");
	mlx_string_put(fraki->hinit, fraki->hwin, 18, 165, 0xDEEDD3,
	"Click 'Z' for light theme with dark fractal");
	mlx_string_put(fraki->hinit, fraki->hwin, 18, 195, 0xDEEDD3,
	"Click 'X' for dark theme with light fractal");
	mlx_string_put(fraki->hinit, fraki->hwin, 45, 225, 0xDEEDD3,
	"Click 'C' || 'V' just cool gradient mode");
	mlx_string_put(fraki->hinit, fraki->hwin, 65, 255, 0xDEEDD3,
	"And 'B' for awesome raindbow fractal");
	mlx_string_put(fraki->hinit, fraki->hwin, 15, 285, 0xDEEDD3,
	"Play with 1 2 3 for +RGB and 4 5 6 for -RGB");
	mlx_string_put(fraki->hinit, fraki->hwin, 150, 315, 0xbf2550,
	"AND only for Julia");
	mlx_string_put(fraki->hinit, fraki->hwin, 10, 345, 0xDEEDD3,
	"start/stop dance Julia: RightMouseButton");
	mlx_loop(fraki->hinit);
}
