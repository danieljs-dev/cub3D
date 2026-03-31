/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:46:58 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/06 22:49:15 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	s;
	double	c;

	s = sin(angle);
	c = cos(angle);
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * c - p->dir_y * s;
	p->dir_y = old_dir_x * s + p->dir_y * c;
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * c - p->plane_y * s;
	p->plane_y = old_plane_x * s + p->plane_y * c;
}

void	player_rotate_update(t_app *app, double dt)
{
	double	angle;

	if (!app)
		return ;
	angle = 0.0;
	if (app->input.left)
		angle -= ROT_SPEED * dt;
	if (app->input.right)
		angle += ROT_SPEED * dt;
	if (angle != 0.0)
		rotate_player(&app->player, angle);
}
