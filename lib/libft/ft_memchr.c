/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:35:12 by dajesus-          #+#    #+#             */
/*   Updated: 2024/10/25 17:49:21 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*s_copy;

	i = 0;
	s_copy = (const unsigned char *)s;
	while (i < n)
	{
		if (s_copy[i] == (unsigned char)c)
			return ((void *)&s_copy[i]);
		i++;
	}
	return (NULL);
}
