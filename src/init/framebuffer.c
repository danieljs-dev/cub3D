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
	if (!app || !app->mlx.ptr)
		return (0);
	app->frame.w = CUB3D_WIN_W;
	app->frame.h = CUB3D_WIN_H;
	app->frame.ptr = mlx_new_image(app->mlx.ptr, app->frame.w, app->frame.h);
	if (!app->frame.ptr)
		return (0);
	app->frame.addr = mlx_get_data_addr(app->frame.ptr, &app->frame.bpp,
			&app->frame.line_len, &app->frame.endian);
	if (!app->frame.addr)
		return (0);
	return (1);
}

void	framebuffer_destroy(t_app *app)
{
	if (!app || !app->mlx.ptr)
		return ;
	if (app->frame.ptr)
	{
		mlx_destroy_image(app->mlx.ptr, app->frame.ptr);
		app->frame.ptr = NULL;
		app->frame.addr = NULL;
	}
}
