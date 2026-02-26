/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 04:25:28 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/26 14:26:22 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list args, int fd)
{
	char	*str;
	char	*error_message;

	str = va_arg(args, char *);
	error_message = (char *)get_error_message(ERR_NULL);
	if (!str)
	{
		ft_putstr_fd(error_message, fd);
		return (ft_strlen(error_message));
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	print_char(va_list args, int fd)
{
	char		c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, fd);
	return (1);
}
