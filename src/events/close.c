/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:20:24 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/05 23:42:36 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

int	on_destroy(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app || !app->mlx.ptr)
		return (0);
	app->running = 0;
	mlx_loop_end(app->mlx.ptr);
	return (0);
}

static void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
}

int	on_keydown(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app)
		return (0);
	if (keycode == XK_ESCAPE)
		return (on_destroy(param));
	if (keycode == XK_LEFT)
		rotate_player(&app->player, -ROT_SPEED);
	if (keycode == XK_RIGHT)
		rotate_player(&app->player, ROT_SPEED);
	return (0);
}
