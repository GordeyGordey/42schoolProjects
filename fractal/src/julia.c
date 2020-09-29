/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:49 by grinko            #+#    #+#             */
/*   Updated: 2020/03/05 15:30:50 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_motion(int x, int y, t_fractal *fraki)
{
	if (fraki->jul)
	{
		fraki->k = init_complex(
		4 * ((double)x / WIDTH - 0.5),
		4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		makimaki(fraki);
	}
	return (0);
}

void	crth(pthread_t thread[3], t_fractal *fraki)
{
	pthread_create(&thread[0], NULL, fun2, fraki);
	pthread_create(&thread[1], NULL, fun2, fraki);
	pthread_create(&thread[2], NULL, fun2, fraki);
}

void	jeq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki)
{
	*c = init_complex(yoou->re, yoou->im);
	*iter = 0;
	while (((c->re * c->re) + (c->im * c->im) <= 4) && *iter < fraki->maxiter)
	{
		*c = init_complex(c->re * c->re - c->im * c->im + fraki->k.re, 2.0 *
		c->re * c->im + fraki->k.im);
		*iter += 1;
	}
}

void	julia(t_fractal *fraki)
{
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;
	pthread_t	thread[3];

	i.y = -fraki->ymov;
	iter = 0;
	crth(thread, fraki);
	while (i.y + fraki->ymov < HEIGHT)
	{
		yoou.im = fraki->max.im - i.y * fraki->mudlark.im;
		i.x = -fraki->xmov;
		while (i.x + fraki->xmov < WIDTH)
		{
			yoou.re = fraki->min.re + i.x * fraki->mudlark.re;
			jeq(&c, &yoou, &iter, fraki);
			i.x++;
			color(fraki, iter, i.x + fraki->xmov, i.y + fraki->ymov);
		}
		i.y += 4;
	}
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
}
