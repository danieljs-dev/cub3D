/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:33:08 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/08 01:29:37 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_calc_dir(t_app *app, int screen_x, t_ray *ray)
{
	t_raycore	core;

	raycore_init(app, screen_x, &core);
	ray->camera_x = core.camera_x;
	ray->dir_x = core.ray_dir_x;
	ray->dir_y = core.ray_dir_y;
}

static void	ray_calc_delta(t_player *p, t_ray *ray)
{
	ray->map_x = (int)p->x;
	ray->map_y = (int)p->y;
	ray->delta_dist_x = RAY_HUGE;
	ray->delta_dist_y = RAY_HUGE;
	if (ray->dir_x != 0.0)
		ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y != 0.0)
		ray->delta_dist_y = fabs(1.0 / ray->dir_y);
}

static void	ray_calc_step_side(t_player *p, t_ray *ray)
{
	if (ray->dir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->x - (double)ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((double)ray->map_x + 1.0 - p->x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0.0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->y - (double)ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((double)ray->map_y + 1.0 - p->y)
			* ray->delta_dist_y;
	}
}

void	ray_init(t_app *app, int screen_x, t_ray *ray)
{
	t_player	*p;

	if (!ray)
		return ;
	ft_bzero(ray, sizeof(*ray));
	if (!app)
		return ;
	p = &app->player;
	ray_calc_dir(app, screen_x, ray);
	ray_calc_delta(p, ray);
	ray_calc_step_side(p, ray);
	ray->hit = 0;
}
