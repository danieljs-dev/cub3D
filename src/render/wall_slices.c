/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:08:09 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/09 01:07:05 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	wall_color(int side)
{
	if (side == 1)
		return (0x00777777);
	return (0x00BBBBBB);
}

static double	ray_perp_dist(t_app *app, t_ray *ray)
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

static void	draw_vline(t_img *img, t_draw *draw)
{
	char	*dst;
	int		bytes;
	int		y;
	int		y_end;

	if (!img || !img->addr || img->bpp <= 0 || !draw)
		return ;
	bytes = img->bpp / 8;
	if (draw->x < 0 || draw->x >= img->w || bytes <= 0)
		return ;
	y = draw->start;
	y_end = draw->end;
	if (y < 0)
		y = 0;
	if (y_end >= img->h)
		y_end = img->h - 1;
	while (y <= y_end)
	{
		dst = img->addr + (y * img->line_len) + (draw->x * bytes);
		ft_memcpy(dst, &draw->color, bytes);
		y++;
	}
}

static void	render_column(t_app *app, t_img *img, int x)
{
	t_ray		ray;
	t_draw		draw;
	double		dist;
	int			line_h;

	ray_init(app, x, &ray);
	ray_dda(app, &ray);
	dist = ray_perp_dist(app, &ray);
	if (dist < 0.0001)
		dist = 0.0001;
	line_h = (int)((double)img->h / dist);
	draw.x = x;
	draw.start = (-line_h / 2) + (img->h / 2);
	draw.end = (line_h / 2) + (img->h / 2);
	draw.color = wall_color(ray.side);
	draw_vline(img, &draw);
}

void	render_walls(t_app *app)
{
	t_img	*img;
	int		x;

	if (!app || !app->file)
		return ;
	img = &app->frame;
	if (!img || !img->addr || img->w <= 0 || img->h <= 0)
		return ;
	x = 0;
	while (x < img->w)
	{
		render_column(app, img, x);
		x++;
	}
}
