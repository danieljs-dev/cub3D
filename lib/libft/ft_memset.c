/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:45:44 by dajesus-          #+#    #+#             */
/*   Updated: 2024/10/25 17:49:48 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_str;

	i = 0;
	s_str = (unsigned char *)s;
	while (i < n)
	{
		s_str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
