/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 02:42:00 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 14:39:59 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**map_clone(t_file *file);
int		map_cell(char **map, int y, int x);
void	map_mark(char **map, int y, int x, char v);

static int	is_walkable(int c)
{
	return (c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

static int	fill(char **m, int y, int x)
{
	int	c;

	c = map_cell(m, y, x);
	if (c == 0)
		return (0);
	if (c == ' ')
		return (0);
	if (c == 'V')
		return (1);
	if (!is_walkable(c))
		return (1);
	map_mark(m, y, x, 'V');
	if (!fill(m, y + 1, x) || !fill(m, y - 1, x)
		|| !fill(m, y, x + 1) || !fill(m, y, x - 1))
		return (0);
	return (1);
}

static int	validate_all(char **m, t_file *file)
{
	int	y;
	int	x;

	y = 0;
	while (y < file->map_height)
	{
		x = 0;
		while (m[y] && m[y][x])
		{
			if (is_walkable(m[y][x]))
				if (!fill(m, y, x))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	has_walkable(t_file *file)
{
	int	y;
	int	x;

	y = 0;
	while (y < file->map_height)
	{
		x = 0;
		while (file->map[y] && file->map[y][x])
		{
			if (is_walkable(file->map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_map_closed(t_file *file)
{
	char	**m;
	int		ok;
	int		i;

	if (!file || !file->map)
		return (ft_print_error("internal error"));
	if (file->map_height < 3 || file->map_width < 3)
	{
		if (file->map_height == 1)
			return (ft_print_error("unexpected content after map"));
		return (ft_print_error("map too small"));
	}
	if (!has_walkable(file))
		return (ft_print_error("map has no walkable cell"));
	m = map_clone(file);
	if (!m)
		return (ft_print_error("malloc failed"));
	ok = validate_all(m, file);
	i = 0;
	while (m[i])
		free(m[i++]);
	free(m);
	if (!ok)
		return (ft_print_error("map not closed"));
	return (0);
}
