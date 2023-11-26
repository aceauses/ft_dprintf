/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:56 by aceauses          #+#    #+#             */
/*   Updated: 2023/11/26 21:55:51 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c, int fd)
{
	int	i;

	i = 0;
	if (!c)
	{
		write(fd, "(null)", 6);
		i += 6;
	}
	else
	{
		while (c[i])
		{
			ft_putchar(c[i], fd);
			i++;
		}
	}
	return (i);
}
