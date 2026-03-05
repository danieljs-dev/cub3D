/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:42:34 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/27 21:55:16 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	clear_row(char *row, int w, int bytes)
{
	int	x;

	x = 0;
	while (x < w)
	{
		ft_bzero(row + (x * bytes), bytes);
		x++;
	}
}

static void	clear_frame(t_img *img)
{
	int		bytes;
	int		y;

	if (!img || !img->addr)
		return ;
	bytes = img->bpp / 8;
	if (bytes <= 0)
		return ;
	y = 0;
	while (y < img->h)
	{
		clear_row(img->addr + (y * img->line_len), img->w, bytes);
		y++;
	}
}

int	render_frame(t_app *app)
{
	if (!app || !app->mlx.ptr)
		return (0);
	if (!app->mlx.win || !app->frame.ptr)
		return (0);
	player_update(app);
	clear_frame(&app->frame);
	mlx_put_image_to_window(app->mlx.ptr, app->mlx.win, app->frame.ptr, 0, 0);
	return (0);
}
