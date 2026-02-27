/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:42:34 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/26 21:13:50 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	clear_frame(t_img *img)
{
	int		bytes;
	int		y;
	int		x;
	char	*row;

	if (!img || !img->addr)
		return ;
	bytes = img->bpp / 8;
	if (bytes <= 0)
		return ;
	y = 0;
	while (y < img->h)
	{
		row = img->addr + (y * img->line_len);
		x = 0;
		while (x < img->w)
		{
			ft_bzero(row + (x * bytes), bytes);
			x++;
		}
		y++;
	}
}

int	render_frame(t_app *app)
{
	if (!app || !app->mlx.ptr)
		return (0);
	if (!app->mlx.win || !app->frame.ptr)
		return (0);
	clear_frame(&app->frame);
	mlx_put_image_to_window(app->mlx.ptr, app->mlx.win, app->frame.ptr, 0, 0);
	return (0);
}
