/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:47:11 by aceauses          #+#    #+#             */
/*   Updated: 2023/11/27 10:37:39 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_symbol(va_list args, int c, int fd)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int), fd);
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *), fd);
	else if (c == 'd' || c == 'i')
		print += ft_putnmbr(va_arg(args, int), fd);
	else if (c == 'u')
		print += ft_putnmbr_un(va_arg(args, unsigned int), fd);
	else if (c == 'p')
		print += ft_put_ptr(va_arg(args, void *), fd);
	else if (c == 'x' || c == 'X')
		print += ft_print_hex(va_arg(args, unsigned int), c, fd);
	else if (c == '%')
		print += ft_putchar('%', fd);
	return (print);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int		print;
	int		i;
	va_list	args;

	print = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += printf_symbol(args, str[i + 1], fd);
			i++;
		}
		else
			print += ft_putchar(str[i], fd);
		i++;
	}
	va_end(args);
	return (print);
}
