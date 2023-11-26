/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnmbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:38:03 by aceauses          #+#    #+#             */
/*   Updated: 2023/11/26 21:56:58 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_long_base_len(long int index, size_t base)
{
	size_t	i;

	i = 1;
	while (index >= (long int)base)
	{
		index = index / base;
		i++;
	}
	return (i);
}

int	ft_putnmbr(long int n, int fd)
{
	char	*base;
	int		nmbr_len;

	base = "0123456789";
	nmbr_len = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nmbr_len += ft_putnmbr(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnmbr(n / 10, fd);
		ft_putnmbr(n % 10, fd);
	}
	else
		write (1, &base[n], 1);
	nmbr_len += ft_long_base_len(n, ft_strlen_printf(base));
	return (nmbr_len);
}
