/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:42:50 by grinko            #+#    #+#             */
/*   Updated: 2019/11/27 17:52:13 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_check(int **map, t_tetr *tetr, int i1, int j1)
{
	int i;
	int j;
	int k;
	int l;

	i = i1;
	k = 0;
	while (i < (tetr->y + i1))
	{
		l = 0;
		j = j1;
		while (j < tetr->x + j1)
		{
			if (map[i][j] != '.' && tetr->map[k][l] != '.')
			{
				return (0);
			}
			j++;
			l++;
		}
		i++;
		k++;
	}
	return (1);
}

int		add(int **map, t_tetr *tetr, int i1, int j1)
{
	int i;
	int j;
	int k;
	int l;

	i = i1;
	k = 0;
	tetr->ifin = 1;
	while (i < tetr->y + i1)
	{
		l = 0;
		j = j1;
		while (j < tetr->x + j1)
		{
			if (map[i][j] == '.')
				map[i][j] = tetr->map[k][l];
			j++;
			l++;
		}
		i++;
		k++;
	}
	return (1);
}

int		tetr_add(int **map, t_tetr *tetr, int a, t_st **st)
{
	int i;
	int j;

	if (!petrovich(tetr, a, &i, &j))
		return (0);
	while (i < a)
	{
		while (j < a)
		{
			if (i + tetr->y <= a && j + tetr->x <= a)
				if (add_check(map, tetr, i, j))
				{
					st_add(st, tetr->code);
					karasik(&tetr, i, j);
					tetr->onmap = checkif(i * 100 + j, a, map, tetr);
					return (add(map, tetr, i, j));
				}
			j++;
		}
		j = 0;
		i++;
	}
	karasik(&tetr, 0, -1);
	return (0);
}

int		checkall(t_tetr *tetr)
{
	t_tetr *t;

	t = tetr;
	while (t)
	{
		if (!(t->ifin))
			return (0);
		t = t->next;
	}
	return (1);
}

int		fillit(t_tetr *tetr, int a, int last, t_st **st)
{
	int		**map;
	int		n;

	malfil(a, &map);
	n = tetr->code;
	while (1)
	{
		if (tetr_add(map, find_tetr(tetr, n), a, st))
		{
			if (checkall(tetr))
				return (printmap(map, a));
			viktor(tetr, &n, last);
		}
		else
		{
			if ((n = st_pop(st, map, a, tetr)) == 0)
				return (0);
			if (find_tetr(tetr, n)->onmap && !find_tetr(tetr, n)->ifin)
				continue ;
			func(*st, n, tetr, map);
			if (!(*st) && (n == 1 || n == 0 || n > last))
				return (0);
		}
	}
}
