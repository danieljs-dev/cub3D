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

static int	is_wall_cell(t_file *file, int x, int y)
{
	int	len;

	if (!file || !file->map)
		return (1);
	if (x < 0 || y < 0 || y >= file->map_height)
		return (1);
	len = (int)ft_strlen(file->map[y]);
	if (x >= len)
		return (1);
	return (file->map[y][x] == '1');
}

static void	do_step(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	ray_dda(t_app *app, t_ray *ray)
{
	if (!app || !app->file || !ray)
		return ;
	while (!ray->hit)
	{
		do_step(ray);
		ray->hit = is_wall_cell(app->file, ray->map_x, ray->map_y);
	}
}
