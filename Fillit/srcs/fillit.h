/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:42:40 by grinko            #+#    #+#             */
/*   Updated: 2019/11/19 18:00:46 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_tetr
{
	int				ifin;
	int				x;
	int				y;
	int				code;
	int				map[4][4];
	int				fix;
	int				fiy;
	int				onmap;
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_st
{
	int				code;
	struct s_st		*next;
}					t_st;

int					as(int **map);
int					last(t_tetr *tetr);
void				func(t_st *st, int n, t_tetr *tetr, int **map);
void				tprintmap(int map[4][4]);
void				main2(char *buff, t_tetr	*tetr);
void				st_pop2(int **map, int a, int k);
void				mappoint(int **map, int a);
void				clearmap(int **map, int a, int k);
void				karasik(t_tetr **tetr, int i, int j);
void				viktor(t_tetr *tetr, int *n, int last);
int					petrovich(t_tetr *tetr, int a, int *i, int *j);
void				malfil(int a, t_st **st, int ***map);
int					checkif(int k, int a, int **map, t_tetr *tetr);
int					st_pop(t_st **bst, int **map, int a, t_tetr *tetr);
int					add_check(int **map, t_tetr *tetr, int i1, int j1);
int					add(int **map, t_tetr *tetr, int i1, int j1);
int					tetr_add(int **map, t_tetr *tetr, int a, t_st **st);
int					fillit(t_tetr *tetr, int a, int last);
int					checkmap(char *tet);
int					checktetris(char *tet);
int					koltetr(char *s);
int					validinput(char *buff, t_tetr **tetr, int k);
int					checkall(t_tetr *tetr);
int					findcode(int **map, int c, int a);
void				find_x(char **s, int *minx, int *x);
void				find_y(char **s, int *miny, int *y);
void				points(t_tetr **tetr);
void				asmbl_map(char **s, t_tetr **tetr, int x, int y);
void				tet_add(t_tetr **b_t, char **s, int code);
void				st_add(t_st **bst, int code);
int					printmap(int **map, int a);
t_tetr				*tetr_create(char **s, int code);
t_tetr				*find_tetr(t_tetr *tetr, int c);
int					first_t(t_tetr *t, int n, int last);
t_st				*st_create(int code);

#endif
