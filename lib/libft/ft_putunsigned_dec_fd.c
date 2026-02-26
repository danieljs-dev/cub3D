/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_dec_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:07:08 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/12 04:34:28 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_dec_fd(unsigned int n, int fd)
{
	char		buf[10];
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
		buf[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		ft_putchar_fd(buf[--i], fd);
		count++;
	}
	return (count);
}
