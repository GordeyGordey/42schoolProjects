/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:31:39 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 15:22:44 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	beq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki)
{
	*c = init_complex(yoou->re, yoou->im);
	*iter = 0;
	while (((c->re * c->re) + (c->im * c->im) <= 4) && *iter < fraki->maxiter)
	{
		*c = init_complex(c->re * c->re - c->im * c->im + yoou->re,
		-2.0 * fabsl(c->re * c->im) + yoou->im);
		*iter += 1;
	}
}

void	burningship(t_fractal *fraki)
{
	pthread_t	thread[3];
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;

	i.y = -fraki->ymov;
	iter = 0;
	pthcrbs(fraki, thread);
	while (i.y + fraki->ymov < HEIGHT)
	{
		yoou.im = fraki->max.im - i.y * fraki->mudlark.im;
		i.x = -fraki->xmov;
		while (i.x + fraki->xmov < WIDTH)
		{
			yoou.re = fraki->min.re + i.x * fraki->mudlark.re;
			beq(&c, &yoou, &iter, fraki);
			i.x++;
			color(fraki, iter, i.x + fraki->xmov, i.y + fraki->ymov);
		}
		i.y += 4;
	}
	ptjoin(thread);
}

void	pthcrbs(t_fractal *fraki, pthread_t *thread)
{
	pthread_create(&thread[0], NULL, fun4, fraki);
	pthread_create(&thread[1], NULL, fun4, fraki);
	pthread_create(&thread[2], NULL, fun4, fraki);
}
