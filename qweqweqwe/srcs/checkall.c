/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:21:44 by grinko            #+#    #+#             */
/*   Updated: 2019/11/27 17:52:49 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkmap(char *tet)
{
	int i;
	int j;
	int sharp;

	i = 0;
	j = 0;
	sharp = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (!(tet[i * 5 + j] == '.' || tet[i * 5 + j] == '#'))
				return (0);
			if (tet[i * 5 + j] == '#')
				sharp++;
			j++;
		}
		if (tet[i * 5 + j] != '\n')
			return (0);
		i++;
		j = 0;
	}
	if (sharp != 4)
		return (0);
	return (1);
}

int		checktetris(char *tet)
{
	int i;
	int sharp;

	i = 0;
	sharp = 0;
	while (i < 20)
	{
		if (tet[i] == '#')
		{
			if (i >= 1 && tet[i - 1] == '#')
				sharp++;
			if (i < 19 && tet[i + 1] == '#')
				sharp++;
			if (i >= 5 && tet[i - 5] == '#')
				sharp++;
			if (i < 15 && tet[i + 5] == '#')
				sharp++;
		}
		i++;
	}
	if (sharp == 6 || sharp == 8)
		return (1);
	return (0);
}

int		validinput(char *buff, t_tetr **tetr, int k)
{
	int		i;
	char	*block;
	char	**s;
	int		code;

	i = 0;
	code = 'A';
	block = ft_strnew(20);
	while (i < k + 1)
	{
		ft_strncpy(block, &(buff[i * 21]), 20);
		if (!checkmap(block) || !checktetris(block))
		{
			free(block);
			return (0);
		}
		i++;
		s = ft_strsplit(block, '\n');
		tet_add(tetr, s, code);
		code++;
		if (buff[i * 20 + (i - 1)] == '\0')
			break ;
	}
	free(block);
	return (1);
}

int		main(int argc, char **argv)
{
	t_tetr	*tetr;
	char	*buff;
	int		fd;
	int		ret;

	if (argc != 2 || !argv[0])
	{
		ft_putstr("usage: ./fillit <filename>\n");
		exit(1);
	}
	tetr = NULL;
	buff = ft_strnew(666);
	if ((fd = open(argv[1], O_RDONLY)) >= 0)
	{
		ret = read(fd, buff, 666);
		if (validinput(buff, &tetr, koltetr(buff)))
			main2(buff, tetr);
		else
			ft_putstr("error\n");
	}
	if (fd < 0)
		ft_putstr("uncorrect file!\n");
	free(buff);
	return (0);
}

void	main2(char *buff, t_tetr *tetr)
{
	int a;
	t_st *st;

	a = 2;
	st = NULL;
	while (a * a < koltetr(buff) * 4)
		a++;
	while (!fillit(tetr, a, 64 + koltetr(buff), &st))
		a++;
	clean(&tetr, &st);
}
