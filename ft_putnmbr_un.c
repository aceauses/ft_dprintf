/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnmbr_un.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:04:46 by aceauses          #+#    #+#             */
/*   Updated: 2023/11/26 21:57:50 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unbr_base_len(unsigned long index, size_t base)
{
	size_t	i;

	i = 1;
	while (index >= (unsigned long int)base)
	{
		index = index / base;
		i++;
	}
	return (i);
}

int	ft_putnmbr_un(unsigned int n, int fd)
{
	unsigned int		nmbr_len;

	nmbr_len = 0;
	if (n >= 10)
	{
		ft_putnmbr_un(n / 10, fd);
		ft_putnmbr_un(n % 10, fd);
	}
	else
		ft_putchar(n + 48, fd);
	nmbr_len += ft_unbr_base_len(n, 10);
	return (nmbr_len);
}
