/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:29:02 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/04 21:46:25 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_blocked(t_app *app, double x, double y)
{
	if (!app || !app->file)
		return (1);
	if (map_cell_at(app->file, (int)(x - PLAYER_COLLISION_RADIUS),
		(int)(y - PLAYER_COLLISION_RADIUS)) != '0')
		return (1);
	if (map_cell_at(app->file, (int)(x + PLAYER_COLLISION_RADIUS),
		(int)(y - PLAYER_COLLISION_RADIUS)) != '0')
		return (1);
	if (map_cell_at(app->file, (int)(x - PLAYER_COLLISION_RADIUS),
		(int)(y + PLAYER_COLLISION_RADIUS)) != '0')
		return (1);
	if (map_cell_at(app->file, (int)(x + PLAYER_COLLISION_RADIUS),
		(int)(y + PLAYER_COLLISION_RADIUS)) != '0')
		return (1);
	return (0);
}

int	player_move(t_app *app, double dx, double dy)
{
	double	nx;
	double	ny;
	int		moved;

	if (!app)
		return (0);
	moved = 0;
	nx = app->player.x + dx;
	ny = app->player.y + dy;
	if (!is_blocked(app, nx, app->player.y))
	{
		app->player.x = nx;
		moved = 1;
	}
	if (!is_blocked(app, app->player.x, ny))
	{
		app->player.y = ny;
		moved = 1;
	}
	return (moved);
}
