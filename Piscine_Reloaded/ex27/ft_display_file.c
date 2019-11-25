/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:05:07 by grinko            #+#    #+#             */
/*   Updated: 2019/09/03 21:05:13 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int filename)
{
	char	tmp;

	while (read(filename, &tmp, 1) != 0)
		ft_putchar(tmp);
}

int		main(int argc, char **argv)
{
	int	filename;

	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	filename = open(argv[1], O_RDONLY);
	if (filename == -1)
		return (0);
	display(filename);
	close(filename);
	return (0);
}
