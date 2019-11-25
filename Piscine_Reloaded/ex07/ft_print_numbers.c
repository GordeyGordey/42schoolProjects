/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:42:23 by grinko            #+#    #+#             */
/*   Updated: 2019/09/04 15:43:17 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	int num_count;

	num_count = 48;
	while (num_count < 58)
	{
		ft_putchar(num_count);
		num_count++;
	}
}
