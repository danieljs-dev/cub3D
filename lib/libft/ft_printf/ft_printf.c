/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:36:47 by dajesus-          #+#    #+#             */
/*   Updated: 2024/12/17 21:27:26 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char specifier, va_list ap, int fd)
{
	t_print_func		func;

	func = find_function(specifier);
	if (func)
		return (func(ap, fd));
	else
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				count;
	int				i;
	int				fd;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	fd = STDOUT_FILENO;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += handle_specifier(str[i + 1], ap, fd);
			i += 2;
			continue ;
		}
		count += ((str[i] != '%') * (ft_putchar_fd(str[i], fd), 1));
		i++;
	}
	va_end(ap);
	return (count);
}
