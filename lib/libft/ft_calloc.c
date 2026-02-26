/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:14 by dajesus-          #+#    #+#             */
/*   Updated: 2024/10/25 17:47:24 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	total_size = nmemb * size;
	mem = (char *)malloc(total_size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, total_size);
	return ((void *)mem);
}
