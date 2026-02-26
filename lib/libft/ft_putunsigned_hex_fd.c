/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_hex_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:08:50 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/12 04:35:21 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_hex_fd(unsigned long n, const char *hex_base, int fd)
{
	char		buf[16];
	int			count;
	int			i;

	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (n > 0)
	{
		buf[i++] = hex_base[n % 16];
		n = n / 16;
	}
	while (--i >= 0)
	{
		ft_putchar_fd(buf[i], fd);
		count++;
	}
	return (count);
}
