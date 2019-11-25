/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:42:52 by grinko            #+#    #+#             */
/*   Updated: 2019/11/19 17:46:31 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_st	*st_create(int code)
{
	t_st *st;

	if (!(st = (t_st*)malloc(sizeof(t_st))))
		return (NULL);
	st->code = code;
	st->next = NULL;
	return (st);
}

void	st_add(t_st **bst, int code)
{
	t_st *st;

	st = st_create(code);
	st->next = *bst;
	*bst = st;
}

int		st_pop(t_st **bst, int **map, int a, t_tetr *tetr)
{
	int		i;
	int		k;
	t_tetr	*t;

	if (!(*bst))
		return (0);
	k = (*bst)->code;
	t = find_tetr(tetr, k);
	t->ifin = 0;
	if (!(*bst)->next)
	{
		clearmap(map, a, k);
		*bst = NULL;
		return (k);
	}
	i = 0;
	*bst = (*bst)->next;
	st_pop2(map, a, k);
	return (k);
}

void	st_pop2(int **map, int a, int k)
{
	int		i;
	int		j;

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

int		checkif(int k, int a, int **map, t_tetr *tetr)
{
	int i;
	int j;

	i = k / 100;
	j = k % 100 + 1;
	if (j >= a)
	{
		j = 0;
		i++;
		if (i >= a)
			return (0);
	}
	while (i < a)
	{
		while (j < a)
		{
			if (i + tetr->y <= a && j + tetr->x <= a)
				if (add_check(map, tetr, i, j))
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
