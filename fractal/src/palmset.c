/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palmset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:34:44 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 15:15:46 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	neq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki)
{
	*c = init_complex(yoou->re, yoou->im);
	*iter = 0;
	while (((c->re * c->re) + (c->im * c->im) <= 4) && *iter < fraki->maxiter)
	{
		*c = init_complex(c->re * c->re - c->im * c->im + 0.9 * c->im,
		2.0 * c->re * c->im + (-1.3) * c->re);
		*iter += 1;
	}
}

void	threadcr(t_fractal *fraki, pthread_t thread[3])
{
	pthread_create(&thread[0], NULL, fun5, fraki);
	pthread_create(&thread[1], NULL, fun5, fraki);
	pthread_create(&thread[2], NULL, fun5, fraki);
}

void	palmset(t_fractal *fraki)
{
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;
	pthread_t	thread[3];

	threadcr(fraki, thread);
	i.y = -fraki->ymov;
	while (i.y + fraki->ymov < HEIGHT)
	{
		yoou.im = fraki->max.im - i.y * fraki->mudlark.im;
		i.x = -fraki->xmov;
		while (i.x + fraki->xmov < WIDTH)
		{
			yoou.re = fraki->min.re + i.x * fraki->mudlark.re;
			neq(&c, &yoou, &iter, fraki);
			i.x++;
			color(fraki, iter, i.x + fraki->xmov, i.y + fraki->ymov);
		}
		i.y += 4;
	}
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
}
