/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:47:10 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/26 20:12:02 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	framebuffer_init(t_app *app)
{
	mlx_image_t	*img;

	if (!app || !app->mlx.ptr)
		return (0);
	app->frame.w = CUB3D_WIN_W;
	app->frame.h = CUB3D_WIN_H;
	img = mlx_new_image(app->mlx.ptr, app->frame.w, app->frame.h);
	if (!img)
		return (0);
	app->frame.ptr = img;
	app->frame.addr = (char *)img->pixels;
	app->frame.bpp = 32;
	app->frame.line_len = app->frame.w * 4;
	app->frame.endian = 0;
	app->ray_camera_step = RAYCORE_CAM_SCALE / (double)app->frame.w;
	return (1);
}

void	framebuffer_destroy(t_app *app)
{
	if (!app || !app->mlx.ptr)
		return ;
	if (app->frame.ptr)
	{
		mlx_delete_image(app->mlx.ptr, app->frame.ptr);
		app->frame.ptr = NULL;
		app->frame.addr = NULL;
	}
}
