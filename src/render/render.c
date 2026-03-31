/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:42:34 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/09 22:50:11 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	rgb_to_int(t_rgb color)
{
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

static void	fill_background_half(t_img *img, int start, int end, unsigned int c)
{
	int		x;
	int		y;
	char	*dst;

	if (img->bpp != 32)
		return ;
	y = start;
	while (y < end)
	{
		x = 0;
		while (x < img->w)
		{
			dst = img->addr + (y * img->line_len) + (x * 4);
			dst[0] = (char)(c >> 24);
			dst[1] = (char)(c >> 16);
			dst[2] = (char)(c >> 8);
			dst[3] = (char)(c);
			x++;
		}
		y++;
	}
}

static void	draw_background(t_app *app)
{
	unsigned int	c_color;
	unsigned int	f_color;

	if (!app || !app->frame.addr)
		return ;
	c_color = rgb_to_int(app->ceiling);
	f_color = rgb_to_int(app->floor);
	fill_background_half(&app->frame, 0, app->frame.h / 2, c_color);
	fill_background_half(&app->frame, app->frame.h / 2, app->frame.h, f_color);
}

void	render_frame(t_app *app)
{
	if (!app || !app->mlx.ptr)
		return ;
	if (!app->frame.ptr)
		return ;
	player_update(app);
	draw_background(app);
	render_walls(app);
	if (FPS_DISPLAY)
		fps_draw(app);
}
