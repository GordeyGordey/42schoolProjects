/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:42:08 by grinko            #+#    #+#             */
/*   Updated: 2019/09/04 15:42:12 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int alph_count;

	alph_count = 97;
	while (alph_count < 123)
	{
		ft_putchar(alph_count);
		alph_count++;
	}
}
