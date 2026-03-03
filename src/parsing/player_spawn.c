/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15∶21∶07 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 16:56:44 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_spawn_char(int c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	mark_spawn(t_app *app, t_file *file, int x, int y)
{
	if (app->spawn_dir == 0)
	{
		app->spawn_x = x;
		app->spawn_y = y;
		app->spawn_dir = file->map[y][x];
	}
	file->map[y][x] = '0';
	return (1);
}

static int	count_spawns(t_app *app, t_file *file)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < file->map_height)
	{
		x = 0;
		while (file->map[y] && file->map[y][x])
		{
			if (is_spawn_char(file->map[y][x]))
				count += mark_spawn(app, file, x, y);
			x++;
		}
		y++;
	}
	return (count);
}

int	validate_player_spawn(t_app *app, t_file *file)
{
	int	count;

	if (!app || !file || !file->map)
		return (ft_print_error("internal error"));
	app->spawn_x = -1;
	app->spawn_y = -1;
	app->spawn_dir = 0;
	count = count_spawns(app, file);
	if (count == 0)
		return (ft_print_error("missing player spawn"));
	if (count > 1)
		return (ft_print_error("multiple player spawns"));
	return (0);
}
