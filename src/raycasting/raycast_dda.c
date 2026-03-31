/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:33:16 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/08 01:29:53 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	do_step(t_ray *ray)
{
	int	step_in_x;

	step_in_x = (ray->side_dist_x < ray->side_dist_y);
	ray->side_dist_x += ray->delta_dist_x * step_in_x;
	ray->map_x += ray->step_x * step_in_x;
	ray->side_dist_y += ray->delta_dist_y * (1 - step_in_x);
	ray->map_y += ray->step_y * (1 - step_in_x);
	ray->side = (step_in_x == 0);
}

void	ray_dda(t_app *app, t_ray *ray)
{
	if (!app || !app->file || !ray)
		return ;
	while (!ray->hit)
	{
		do_step(ray);
		ray->hit = (map_cell_at(app->file, ray->map_x, ray->map_y) != '0');
	}
}
