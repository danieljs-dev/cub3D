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

static void	set_tex_params(t_app *app, t_ray *r, t_tex_col *s, double dist)
{
	if (r->side == 0)
	{
		s->wall_x = app->player.y + dist * r->dir_y;
		s->tex_idx = TEX_WE;
		if (r->dir_x > 0)
			s->tex_idx = TEX_EA;
	}
	else
	{
		s->wall_x = app->player.x + dist * r->dir_x;
		s->tex_idx = TEX_NO;
		if (r->dir_y > 0)
			s->tex_idx = TEX_SO;
	}
	s->wall_x -= floor(s->wall_x);
}

static void	draw_tex_col(t_img *img, t_tex_col *s, t_ray *r, t_img *tex)
{
	int		t_x;
	double	step;
	double	pos;
	int		y;
	int		b;

	if (!img || !img->addr || img->bpp <= 0 || !tex || !tex->addr || !s || !r)
		return ;
	b = img->bpp / 8;
	if (s->x < 0 || s->x >= img->w || b <= 0 || tex->w <= 0 || tex->h <= 0)
		return ;
	t_x = (int)(s->wall_x * (double)tex->w);
	if (t_x >= tex->w)
		t_x = tex->w - 1;
	if ((r->side == 0 && r->dir_x < 0) || (r->side == 1 && r->dir_y > 0))
		t_x = tex->w - t_x - 1;
	if (t_x < 0)
		t_x = 0;
	step = 1.0 * tex->h / s->line_h;
	pos = (s->start - img->h / 2 + s->line_h / 2) * step;
	y = s->start;
	while (y <= s->end)
	{
		if ((int)pos >= 0 && (int)pos < tex->h)
			ft_memcpy(img->addr + (y * img->line_len) + (s->x * b),
				tex->addr + ((int)pos * tex->line_len) + (t_x * b), b);
		pos += step;
		y++;
	}
}

static void	render_column(t_app *app, t_img *img, int x)
{
	t_ray		ray;
	t_tex_col	s;
	double		dist;

	ray_init(app, x, &ray);
	ray_dda(app, &ray);
	dist = ray_perp_dist(app, &ray);
	if (dist < 0.0001)
		dist = 0.0001;
	s.line_h = (int)((double)img->h / dist);
	s.x = x;
	s.start = (-s.line_h / 2) + (img->h / 2);
	s.end = (s.line_h / 2) + (img->h / 2);
	if (s.start < 0)
		s.start = 0;
	if (s.end >= img->h)
		s.end = img->h - 1;
	set_tex_params(app, &ray, &s, dist);
	draw_tex_col(img, &s, &ray, &app->wall_text[s.tex_idx]);
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
