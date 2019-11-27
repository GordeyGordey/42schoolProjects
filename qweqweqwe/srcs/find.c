/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:42:45 by grinko            #+#    #+#             */
/*   Updated: 2019/11/27 17:19:53 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_x(char **s, int *minx, int *x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (s[i][j] == '#')
			{
				if (j > *x)
					*x = j;
				if (j < *minx)
					*minx = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	*x = *x - *minx + 1;
}

void	find_y(char **s, int *miny, int *y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (s[i][j] == '#')
			{
				if (i > *y)
					*y = i;
				if (i < *miny)
					*miny = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	*y = *y - *miny + 1;
}

void	points(t_tetr **tetr)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*tetr)->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	asmbl_map(char **s, t_tetr **tetr, int x, int y)
{
	int i;
	int j;

	i = 0;
	points(tetr);
	while (i < (*tetr)->y)
	{
		j = 0;
		while (j < (*tetr)->x)
		{
			if (s[i + y][j + x] == '#')
				(*tetr)->map[i][j] = (*tetr)->code;
			j++;
		}
		i++;
	}
}

void	clean(t_tetr **tetr, t_st **st)
{
	t_tetr	*curt;
	t_st	*curs;

	curt = NULL;
	curs = NULL;
	while(*tetr)
	{
		curt = *tetr;
		*tetr = (*tetr)->next;
		free (curt);
	}
	while(*st)
	{
		curs = *st;
		*st = (*st)->next;
		free (curs);
	}
	free(*tetr);
	free(*st);
}
