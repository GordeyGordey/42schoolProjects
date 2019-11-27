/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:42:55 by grinko            #+#    #+#             */
/*   Updated: 2019/11/27 16:54:58 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*tetr_create(char **s, int code)
{
	t_tetr	*tetr;
	int		x;
	int		y;

	tetr = NULL;
	if (!(tetr = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	x = 4;
	y = 4;
	tetr->fix = -1;
	tetr->fiy = 0;
	tetr->x = 0;
	tetr->y = 0;
	tetr->next = NULL;
	tetr->code = code;
	tetr->onmap = 0;
	tetr->ifin = 0;
	find_x(s, &x, &tetr->x);
	find_y(s, &y, &tetr->y);
	asmbl_map(s, &tetr, x, y);
	return (tetr);
}

void	tet_add(t_tetr **b_t, char **s, int code)
{
	t_tetr *tetr;

	if (!(*b_t))
	{
		*b_t = tetr_create(s, code);
		return ;
	}
	tetr = *b_t;
	while (tetr->next)
		tetr = tetr->next;
	tetr->next = tetr_create(s, code);
}

t_tetr	*find_tetr(t_tetr *tetr, int c)
{
	t_tetr *cur;

	cur = tetr;
	while (cur && cur->code != c)
		cur = cur->next;
	return (cur);
}

int		koltetr(char *s)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i - 1] == '\n')
			k++;
		i++;
	}
	return (k + 1);
}

int		first_t(t_tetr *t, int n, int last)
{
	t_tetr *u;

	if (n > last)
		return (0);
	u = find_tetr(t, n);
	while (u && u->ifin)
		u = u->next;
	if (!u)
		return (0);
	return (u->code);
}
