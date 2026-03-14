/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20∶31∶19 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/06 22:49:08 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycore_init(t_app *app, int screen_x, t_raycore *out)
{
	double	cam_x;
	t_img	*img;

	if (!out)
		return ;
	out->camera_x = 0.0;
	out->ray_dir_x = 0.0;
	out->ray_dir_y = 0.0;
	if (!app)
		return ;
	img = &app->frame;
	if (!img || img->w <= 0)
		return ;
	cam_x = (RAYCORE_CAM_SCALE * (double)screen_x) / (double)img->w
		- RAYCORE_CAM_SHIFT;
	out->camera_x = cam_x;
	out->ray_dir_x = app->player.dir_x + app->player.plane_x * cam_x;
	out->ray_dir_y = app->player.dir_y + app->player.plane_y * cam_x;
}

double	ray_perp_dist(t_app *app, t_ray *ray)
{
	if (!app || !ray)
		return (RAY_HUGE);
	if (ray->side == 0)
	{
		if (ray->dir_x == 0.0)
			return (RAY_HUGE);
		return (((double)ray->map_x - app->player.x
				+ (1.0 - (double)ray->step_x) / 2.0) / ray->dir_x);
	}
	if (ray->dir_y == 0.0)
		return (RAY_HUGE);
	return (((double)ray->map_y - app->player.y
			+ (1.0 - (double)ray->step_y) / 2.0) / ray->dir_y);
}
