/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potoki.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:26 by grinko            #+#    #+#             */
/*   Updated: 2020/03/05 15:30:27 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*fun1(void *arg)
{
	t_fractal	*fraki;
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;

	fraki = (t_fractal *)arg;
	i.y = ++fraki->por - fraki->ymov;
	while (i.y + fraki->ymov < HEIGHT)
	{
		yoou.im = fraki->max.im - i.y * fraki->mudlark.im;
		i.x = -fraki->xmov;
		while (i.x + fraki->xmov < WIDTH)
		{
			yoou.re = fraki->min.re + i.x * fraki->mudlark.re;
			meq(&c, &yoou, &iter, fraki);
			i.x++;
			color(fraki, iter, i.x + fraki->xmov, i.y + fraki->ymov);
		}
		i.y += 4;
	}
	pthread_exit(0);
}

void	*fun2(void *arg)
{
	t_fractal	*fraki;
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;

	fraki = (t_fractal *)arg;
	i.y = ++fraki->por - fraki->ymov;
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
	pthread_exit(0);
}

void	*fun3(void *arg)
{
	t_fractal	*fraki;
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;

	fraki = (t_fractal *)arg;
	i.y = ++fraki->por - fraki->ymov;
	while (i.y + fraki->ymov < HEIGHT)
	{
		yoou.im = fraki->max.im - i.y * fraki->mudlark.im;
		i.x = -fraki->xmov;
		while (i.x + fraki->xmov < WIDTH)
		{
			yoou.re = fraki->min.re + i.x * fraki->mudlark.re;
			mbeq(&c, &yoou, &iter, fraki);
			i.x++;
			color(fraki, iter, i.x + fraki->xmov, i.y + fraki->ymov);
		}
		i.y += 4;
	}
	pthread_exit(0);
}

void	*fun4(void *arg)
{
	t_fractal	*fraki;
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;

	fraki = (t_fractal *)arg;
	i.y = ++fraki->por - fraki->ymov;
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
	pthread_exit(0);
}

void	*fun5(void *arg)
{
	t_fractal	*fraki;
	t_v2		i;
	int			iter;
	t_c			yoou;
	t_c			c;

	fraki = (t_fractal *)arg;
	i.y = ++fraki->por - fraki->ymov;
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
	pthread_exit(0);
}
