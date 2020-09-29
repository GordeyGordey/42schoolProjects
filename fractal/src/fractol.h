/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:30:42 by grinko            #+#    #+#             */
/*   Updated: 2020/03/12 16:02:35 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>

# define WIDTH 500
# define HEIGHT 500
# define SACSIA 1.1111111111111125
# define USE "Use + - to move"
# define ARGER "Wrong arguments! Chose julia mandelbrot burningship or palmset"

typedef struct	s_snastupivshimnovimgodom
{
	long double	re;
	long double	im;
}				t_c;

typedef struct	s_v2
{
	int	x;
	int	y;
}				t_v2;

typedef struct	s_fractal
{
	void				*init;
	void				*win;
	void				*img;
	void				*hinit;
	void				*hwin;
	int					fractal;
	char				*olya;
	int					pixb;
	int					strb;
	int					maxiter;
	int					iter;
	int					red;
	int					green;
	int					blue;
	int					x;
	int					y;
	int					jul;
	int					tcol;
	long long int		xmov;
	long long int		ymov;
	int					por;
	t_c					mudlark;
	t_c					min;
	t_c					max;
	t_c					k;
	t_c					yoou;
	t_c					c;
}				t_fractal;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

void			*fun1(void *arg);
void			*fun2(void *arg);
void			*fun3(void *arg);
void			*fun4(void *arg);
void			*fun5(void *arg);
void			*juli(void *arg);
void			mbeq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki);
void			neq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki);
void			meq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki);
void			beq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki);
void			jeq(t_c *c, t_c *yoou, int *iter, t_fractal *fraki);
void			window_init(t_fractal *fraki);
void			disiserrorbitch(char *str);
void			smandelbrot(t_fractal *fraki);
void			default_init(t_fractal *fraki);
void			color(t_fractal *fraki, int iter, int x, int y);
t_c				init_complex(double re, double im);
int				select_fractal(char **argv, t_fractal *fraki);
void			julia(t_fractal *fraki);
void			mandelbrot(t_fractal *fraki);
void			makimaki(t_fractal *fraki);
void			pixeldraw(t_fractal *fraki, t_color *col);
t_color			*colors(t_fractal *fraki);
void			mandelbar(t_fractal *fraki);
void			burningship(t_fractal *fraki);
void			palmset(t_fractal *fraki);
int				julia_motion(int x, int y, t_fractal *fraki);

void			draw(int x, int y, t_fractal *fraki, t_color *co);
int				pkey(int key, t_fractal *fraki);
int				mclick(int key, int x, int y, t_fractal *fraki);
void			initall(t_fractal *fraki, char **argv);
void			helpwin(t_fractal *fraki);

void			pthcrmb(t_fractal *fraki, pthread_t *thread);
void			pthcrbs(t_fractal *fraki, pthread_t *thread);
void			ptjoin(pthread_t *thread);

#endif
