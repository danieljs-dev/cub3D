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
	return ((color.r << 16) | (color.g << 8) | color.b);
}

static void	fill_background_half(t_img *img, int start, int end, unsigned int c)
{
	int		x;
	int		y;
	int		bytes;
	char	*dst;

	bytes = img->bpp / 8;
	if (bytes <= 0)
		return ;
	y = start;
	while (y < end)
	{
		x = 0;
		while (x < img->w)
		{
			dst = img->addr + (y * img->line_len) + (x * bytes);
			ft_memcpy(dst, &c, bytes);
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

static void	draw_fps(t_app *app)
{
	char	*num;
	char	*str;

	num = ft_itoa((int)app->fps);
	if (!num)
		return ;
	str = ft_strjoin("FPS: ", num);
	free(num);
	if (!str)
		return ;
	mlx_string_put(app->mlx.ptr, app->mlx.win, 10, 20, 0xFFFFFF, str);
	free(str);
}

int	render_frame(t_app *app)
{
	if (!app || !app->mlx.ptr)
		return (0);
	if (!app->mlx.win || !app->frame.ptr)
		return (0);
	player_update(app);
	draw_background(app);
	render_walls(app);
	mlx_put_image_to_window(app->mlx.ptr, app->mlx.win, app->frame.ptr, 0, 0);
	if (FPS_DISPLAY)
		draw_fps(app);
	return (0);
}
