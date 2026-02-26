/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 04:23:40 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/26 14:25:12 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args, int fd)
{
	int		value;
	int		len;
	int		tmp_value;

	len = 0;
	value = va_arg(args, int);
	tmp_value = value;
	if (value == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd), 11);
	if (value < 0)
	{
		len++;
		tmp_value = -tmp_value;
	}
	if (value == 0)
		return (ft_putchar_fd('0', fd), 1);
	while (tmp_value > 0)
	{
		tmp_value = tmp_value / 10;
		len++;
	}
	ft_putnbr_fd(value, fd);
	return (len);
}

int	print_unsigned_dec(va_list args, int fd)
{
	unsigned int		value;
	int					count;

	count = 0;
	value = va_arg(args, unsigned int);
	count += ft_putunsigned_dec_fd(value, fd);
	return (count);
}
