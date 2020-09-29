/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:58 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 15:19:59 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	chcol(t_color *co, t_fractal *fraki, double o)
{
	if (fraki->tcol == 3)
	{
		co->red = (int)((1 - o) * fraki->red);
		co->green = (int)((1 - o) * fraki->green);
		co->blue = (int)((1 - o) * fraki->blue);
	}
	if (fraki->tcol == 2)
	{
		co->red = (int)((o) * fraki->red);
		co->green = (int)((o) * fraki->green);
		co->blue = (int)((o) * fraki->blue);
	}
	if (fraki->tcol == 1)
	{
		co->red = (int)((1 - o) * o * fraki->red);
		co->green = (int)((1 - o) * o * fraki->green);
		co->blue = (int)((1 - o) * o * fraki->blue);
	}
	if (fraki->tcol == 4)
	{
		co->red = (int)((1 - o) * o * o * fraki->red);
		co->green = (int)((1 - o) * (1 - o) * o * fraki->green);
		co->blue = (int)((1 - o) * o * fraki->blue);
	}
}

void	color(t_fractal *fraki, int iter, int x, int y)
{
	double		o;
	t_color		*co;

	if (y > HEIGHT || x > WIDTH || x < 0 || y < 0)
		return ;
	if (!(co = (t_color *)malloc(sizeof(t_color))))
		disiserrorbitch("Error");
	o = (double)iter / (double)fraki->maxiter;
	chcol(co, fraki, o);
	if (fraki->tcol == 5)
	{
		co->red = (int)((1 - o) * o * 14 * fraki->red);
		co->green = (int)((1 - o) * 35 * o * fraki->green);
		co->blue = (int)((1 - o) * o * 120 * o * fraki->blue);
	}
	draw(x, y, fraki, co);
	free(co);
}

void	draw(int x, int y, t_fractal *fraki, t_color *co)
{
	int pixel;

	pixel = (x * fraki->pixb / 8) + (y * fraki->strb);
	fraki->olya[pixel] = (char)(co->blue);
	fraki->olya[++pixel] = (char)(co->green);
	fraki->olya[++pixel] = (char)(co->red);
}
