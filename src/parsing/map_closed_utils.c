/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 02:42:11 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 14:38:52 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_clone(char **clone, int used)
{
	int	i;

	i = 0;
	while (i < used)
	{
		free(clone[i]);
		i++;
	}
	free(clone);
}

char	**map_clone(t_file *file)
{
	char	**c;
	int		i;

	c = ft_calloc(file->map_height + 1, sizeof(char *));
	if (!c)
		return (NULL);
	i = 0;
	while (i < file->map_height)
	{
		c[i] = ft_strdup(file->map[i]);
		if (!c[i])
		{
			free_clone(c, i);
			return (NULL);
		}
		i++;
	}
	return (c);
}

int	map_cell(char **map, int y, int x)
{
	if (y < 0 || x < 0)
		return (0);
	if (!map[y])
		return (0);
	if (x >= (int)ft_strlen(map[y]))
		return (0);
	return (map[y][x]);
}

void	map_mark(char **map, int y, int x, char v)
{
	if (y < 0 || x < 0)
		return ;
	if (!map[y])
		return ;
	if (x >= (int)ft_strlen(map[y]))
		return ;
	map[y][x] = v;
}

int	map_cell_at(t_file *file, int x, int y)
{
	if (!file || !file->map)
		return (0);
	if (y >= file->map_height)
		return (0);
	return (map_cell(file->map, y, x));
}
