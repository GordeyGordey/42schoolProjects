/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapochki.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:42:57 by grinko            #+#    #+#             */
/*   Updated: 2019/11/19 17:48:04 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		printmap(int **map, int a)
{
	int		i;
	int		j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

void	mappoint(int **map, int a)
{
	int i;
	int j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	clearmap(int **map, int a, int k)
{
	int i;
	int j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			if (map[i][j] == k)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	func(t_st *st, int n, t_tetr *tetr, int **map)
{
	while (st)
	{
		n = first_t(tetr, n + 1, last(tetr));
		if (n == 0)
		{
			n = st_pop(&st, map, as(map), tetr) + 1;
			n = first_t(tetr, n, last(tetr));
		}
		else
		{
			break ;
		}
	}
}

int		as(int **map)
{
	int *ar;
	int i;

	ar = map[0];
	i = 0;
	while (ar[i])
		i++;
	return (i);
}
