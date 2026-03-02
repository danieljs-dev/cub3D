/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:39:33 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/01 14:40:07 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_split(char **parts)
{
	int	i;

	if (!parts)
		return ;
	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

int	is_valid_component(char *s)
{
	s = ft_skip_spaces(s);
	if (*s == '\0')
		return (0);
	while (ft_isdigit(*s))
		s++;
	s = ft_skip_spaces(s);
	return (*s == '\0');
}
