/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:58:22 by grinko            #+#    #+#             */
/*   Updated: 2019/09/12 12:01:27 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_arr(char **arr, int i)
{
	while (--i)
		free(arr[i]);
	free(arr);
}

static char	*word(char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	oleg;
	int	count;

	i = 0;
	count = 0;
	oleg = 0;
	while (s[i])
	{
		if (s[i] != c && oleg == 0)
		{
			oleg = 1;
			count++;
		}
		else if (s[i] == c && oleg == 1)
			oleg = 0;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s || !(arr = (char **)malloc(sizeof(char *)
					* count_words((char *)s, c) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			if (!(arr[i] = word((char *)s, c)))
			{
				ft_free_arr(arr, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
