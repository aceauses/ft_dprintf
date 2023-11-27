/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:47:00 by aceauses          #+#    #+#             */
/*   Updated: 2023/11/27 10:38:04 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_dprintf(int fd, const char *str, ...);

int		ft_putchar(char c, int fd);
int		ft_putstr(char *c, int fd);
size_t	ft_strlen_printf(const char *str);

int		ft_put_ptr(void *p, int fd);
int		ft_print_hex(unsigned int num, int format, int fd);

int		ft_putnmbr(long int n, int fd);
int		ft_putnmbr_un(unsigned int n, int fd);
#endif
