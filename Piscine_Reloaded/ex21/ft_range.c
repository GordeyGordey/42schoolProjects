/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:40:59 by grinko            #+#    #+#             */
/*   Updated: 2019/09/03 19:41:27 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *qwe;

	i = 0;
	if (min >= max)
		return (0);
	qwe = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		qwe[i] = min;
		i++;
		min++;
	}
	return (qwe);
}
