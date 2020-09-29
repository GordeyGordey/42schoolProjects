/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:34:46 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 15:22:21 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mmove(t_fractal *fraki)
{
	makimaki(fraki);
	return (0);
}

void	m(int x, int y, t_fractal *fraki)
{
	t_c l;
	t_c a;

	l.re = ((x - WIDTH / 2 - fraki->xmov) * fraki->mudlark.re);
	l.im = -((y - HEIGHT / 2 - fraki->ymov) * fraki->mudlark.im);
	fraki->max.re *= 0.9;
	fraki->min.im *= 0.9;
	fraki->min.re *= 0.9;
	l.re *= 0.9;
	l.im *= 0.9;
	fraki->max.im = fraki->min.im + (fraki->max.re - fraki->min.re) *
	HEIGHT / WIDTH;
	a = fraki->mudlark;
	fraki->mudlark = init_complex((fraki->max.re - fraki->min.re) /
	(WIDTH - 1), (fraki->max.im - fraki->min.im) / (HEIGHT - 1));
	fraki->xmov -= ((l.re / fraki->mudlark.re - (l.re / a.re)) * SACSIA);
	fraki->ymov += ((l.im / fraki->mudlark.im - (l.im / a.im)) * SACSIA);
}

void	mm(int x, int y, t_fractal *fraki)
{
	t_c l;
	t_c a;

	l.re = ((x - WIDTH / 2 - fraki->xmov) * fraki->mudlark.re);
	l.im = -((y - HEIGHT / 2 - fraki->ymov) * fraki->mudlark.im);
	fraki->max.re /= 0.9;
	fraki->min.im /= 0.9;
	fraki->min.re /= 0.9;
	l.re /= 0.9;
	l.im /= 0.9;
	fraki->max.im = fraki->min.im + (fraki->max.re - fraki->min.re) *
	HEIGHT / WIDTH;
	a = fraki->mudlark;
	fraki->mudlark = init_complex((fraki->max.re - fraki->min.re) /
	(WIDTH - 1), (fraki->max.im - fraki->min.im) / (HEIGHT - 1));
	fraki->xmov += ((l.re / a.re - (l.re / fraki->mudlark.re)) / SACSIA);
	fraki->ymov -= ((l.im / a.im - (l.im / fraki->mudlark.im)) / SACSIA);
}

int		mclick(int key, int x, int y, t_fractal *fraki)
{
	if (key == 2)
	{
		if (fraki->jul == 0)
			fraki->jul = 1;
		else
			fraki->jul = 0;
	}
	if (key == 4)
		m(x, y, fraki);
	if (key == 5)
		mm(x, y, fraki);
	makimaki(fraki);
	return (0);
}
