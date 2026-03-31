/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:08:09 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/13 21:13:07 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_wall_texture_hit(t_app *app, t_ray *ray,
				t_tex_col *col, double perp_dist)
{
	if (ray->side == 0)
	{
		col->wall_x = app->player.y + perp_dist * ray->dir_y;
		col->tex_idx = TEX_WE;
		if (ray->dir_x > 0)
			col->tex_idx = TEX_EA;
	}
	else
	{
		col->wall_x = app->player.x + perp_dist * ray->dir_x;
		col->tex_idx = TEX_NO;
		if (ray->dir_y > 0)
			col->tex_idx = TEX_SO;
	}
	col->wall_x -= floor(col->wall_x);
}

static int	init_textured_column(t_img *img, t_tex_col *col,
				t_ray *ray, t_img *texture)
{
	if (!img || !img->addr || img->bpp <= 0
		|| !texture || !texture->addr || !col || !ray)
		return (0);
	col->bpp = img->bpp / 8;
	if (col->bpp <= 0 || col->line_h <= 0
		|| col->x < 0 || col->x >= img->w)
		return (0);
	if (texture->w <= 0 || texture->h <= 0)
		return (0);
	col->tex_x = (int)(col->wall_x * (double)texture->w);
	if (col->tex_x >= texture->w)
		col->tex_x = texture->w - 1;
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		col->tex_x = texture->w - col->tex_x - 1;
	if (col->tex_x < 0)
		col->tex_x = 0;
	col->tex_step = 1.0 * texture->h / col->line_h;
	col->tex_pos = (col->start - img->h / 2 + col->line_h / 2) * col->tex_step;
	return (1);
}

static void	draw_textured_column(t_img *img, t_tex_col *col,
				t_ray *ray, t_img *texture)
{
	int		screen_y;
	int		tex_y;

	if (!init_textured_column(img, col, ray, texture))
		return ;
	screen_y = col->start;
	while (screen_y <= col->end)
	{
		tex_y = (int)col->tex_pos;
		if (tex_y >= 0 && tex_y < texture->h)
			ft_memcpy(img->addr + (screen_y * img->line_len)
				+ (col->x * col->bpp),
				texture->addr + (tex_y * texture->line_len)
				+ (col->tex_x * col->bpp), col->bpp);
		col->tex_pos += col->tex_step;
		screen_y++;
	}
}

static void	render_wall_column(t_app *app, t_img *img, int screen_x,
				t_raycore *core)
{
	t_ray		ray;
	t_tex_col	col;
	double		perp_dist;

	ray_init_from_core(app, &ray, core);
	ray_dda(app, &ray);
	perp_dist = ray_perp_dist(app, &ray);
	if (perp_dist < 0.0001)
		perp_dist = 0.0001;
	col.line_h = (int)((double)img->h / perp_dist);
	col.x = screen_x;
	col.start = (-col.line_h / 2) + (img->h / 2);
	col.end = (col.line_h / 2) + (img->h / 2);
	if (col.start < 0)
		col.start = 0;
	if (col.end >= img->h)
		col.end = img->h - 1;
	set_wall_texture_hit(app, &ray, &col, perp_dist);
	draw_textured_column(img, &col, &ray, &app->wall_text[col.tex_idx]);
}

void	render_walls(t_app *app)
{
	t_img		*img;
	t_raycore	core;
	t_raycore	step;
	double		cam_step;
	int			x;

	if (!app || !app->file)
		return ;
	img = &app->frame;
	if (!img || !img->addr || img->w <= 0 || img->h <= 0)
		return ;
	cam_step = app->ray_camera_step;
	core.camera_x = -RAYCORE_CAM_SHIFT;
	core.ray_dir_x = app->player.dir_x + app->player.plane_x * core.camera_x;
	core.ray_dir_y = app->player.dir_y + app->player.plane_y * core.camera_x;
	step.ray_dir_x = app->player.plane_x * cam_step;
	step.ray_dir_y = app->player.plane_y * cam_step;
	x = -1;
	while (++x < img->w)
	{
		render_wall_column(app, img, x, &core);
		core.camera_x += cam_step;
		core.ray_dir_x += step.ray_dir_x;
		core.ray_dir_y += step.ray_dir_y;
	}
}
