/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:58:42 by dajesus-          #+#    #+#             */
/*   Updated: 2025/02/12 03:35:44 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;

	s_len = ft_strlen(s);
	dest = (char *)malloc((s_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, s_len + 1);
	return (dest);
}
