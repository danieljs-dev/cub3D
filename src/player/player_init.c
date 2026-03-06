/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:40:33 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 18:21:07 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_player *player, char spawn_dir)
{
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	if (spawn_dir == 'N')
		player->dir_y = -1.0;
	else if (spawn_dir == 'S')
		player->dir_y = 1.0;
	else if (spawn_dir == 'E')
		player->dir_x = 1.0;
	else if (spawn_dir == 'W')
		player->dir_x = -1.0;
}

int	player_init(t_app *app)
{
	if (!app)
		return (ft_print_error("internal error"));
	if (app->spawn_x < 0 || app->spawn_y < 0)
		return (ft_print_error("invalid player spawn"));
	app->player.x = (double)app->spawn_x + 0.5;
	app->player.y = (double)app->spawn_y + 0.5;
	set_dir(&app->player, app->spawn_dir);
	if (app->player.dir_x == 0.0 && app->player.dir_y == 0.0)
		return (ft_print_error("invalid player direction"));
	return (0);
}
