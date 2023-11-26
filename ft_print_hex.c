/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:18:01 by aceauses          #+#    #+#             */
/*   Updated: 2023/11/26 21:59:49 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int index)
{
	int	i;

	i = 0;
	while (index != 0)
	{
		i++;
		index = index / 16;
	}
	return (i);
}

static void	ft_printf_hex(unsigned int num, int format, int fd)
{
	if (num >= 16)
	{
		ft_printf_hex(num / 16, format, fd);
		ft_printf_hex(num % 16, format, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', fd);
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a', fd);
			else if (format == 'X')
				ft_putchar(num - 10 + 'A', fd);
		}
	}
}

int	ft_print_hex(unsigned int num, int format, int fd)
{
	if (num == 0)
		return (ft_putchar('0', fd));
	else
		ft_printf_hex(num, format, fd);
	return (ft_hex_len(num));
}
