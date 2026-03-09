/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:08:09 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/08 21:54:37 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	wall_color(int side)
{
	if (side == 1)
		return (0x00777777);
	return (0x00BBBBBB);
}

static double	ray_wall_t(t_ray *ray)
{
	if (!ray)
		return (RAY_HUGE);
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	return (ray->side_dist_y - ray->delta_dist_y);
}

static double	ray_player_to_wall_dist(t_ray *ray)
{
	double		t;
	double		len;

	t = ray_wall_t(ray);
	if (t >= RAY_HUGE)
		return (RAY_HUGE);
	len = sqrt(ray->dir_x * ray->dir_x + ray->dir_y * ray->dir_y);
	return (fabs(t) * len);
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
	dist = ray_player_to_wall_dist(&ray);
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
