/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viktor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:47:43 by grinko            #+#    #+#             */
/*   Updated: 2019/11/19 17:47:12 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	viktor(t_tetr *tetr, int *n, int last)
{
	t_tetr *cur;

	cur = tetr;
	*n = first_t(tetr, 65, last);
	while (cur)
	{
		if (cur->code != (*n) && !cur->ifin)
		{
			cur->fix = -1;
			cur->fiy = 0;
		}
		cur = cur->next;
	}
}

int		petrovich(t_tetr *tetr, int a, int *i, int *j)
{
	*i = tetr->fiy;
	*j = tetr->fix + 1;
	if (*j >= a)
	{
		*j = 0;
		(*i)++;
		if (*i >= a)
		{
			karasik(&tetr, 0, -1);
			tetr->onmap = 0;
			return (0);
		}
	}
	return (1);
}

void	karasik(t_tetr **tetr, int i, int j)
{
	(*tetr)->fix = j;
	(*tetr)->fiy = i;
}

void	malfil(int a, t_st **st, int ***map)
{
	int i;

	i = 0;
	*map = (int **)malloc(sizeof(int *) * (a));
	while (i < a)
	{
		(*map)[i] = (int *)malloc(sizeof(int) * (a));
		i++;
	}
	mappoint(*map, a);
	*st = NULL;
}

int		last(t_tetr *tetr)
{
	t_tetr *cur;

	cur = tetr;
	while (cur->next)
		cur = cur->next;
	return (cur->code);
}
