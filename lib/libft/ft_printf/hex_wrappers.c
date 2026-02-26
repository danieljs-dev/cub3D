/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 04:24:50 by dajesus-          #+#    #+#             */
/*   Updated: 2024/12/17 21:22:46 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_lower_hex(va_list args, int fd)
{
	unsigned int		value;

	value = va_arg(args, unsigned int);
	ft_putunsigned_hex_fd(value, HEX_LOWER, fd);
	return (ft_numlen_hex(value));
}

int	print_unsigned_upper_hex(va_list args, int fd)
{
	unsigned int		value;

	value = va_arg(args, unsigned int);
	ft_putunsigned_hex_fd(value, HEX_UPPER, fd);
	return (ft_numlen_hex(value));
}
