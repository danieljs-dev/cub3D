/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexanfe <alexanfe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:29:02 by alexanfe          #+#    #+#             */
/*   Updated: 2026/03/12 22:29:27 by alexanfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_overlay_str(t_app *app, t_overlay_str *o)
{
	char		*num;
	char		*str;
	mlx_image_t	*img;

	if (!app || !app->mlx.ptr || !o || !o->slot)
		return ;
	if (*o->slot)
	{
		mlx_delete_image(app->mlx.ptr, *o->slot);
		*o->slot = NULL;
	}
	num = ft_itoa(o->value);
	if (!num)
		return ;
	str = ft_strjoin(o->prefix, num);
	free(num);
	if (!str)
		return ;
	img = mlx_put_string(app->mlx.ptr, str, 10, o->y);
	free(str);
	if (!img)
		return ;
	if (img->count > 0)
		mlx_set_instance_depth(&img->instances[0], 10);
	*o->slot = img;
}

void	fps_draw(t_app *app)
{
	t_overlay_str	fps;
	t_overlay_str	ms;

	fps.slot = &app->fps_img;
	fps.prefix = "FPS: ";
	fps.value = app->fps_display;
	fps.y = 20;
	ms.slot = &app->ms_img;
	ms.prefix = "MS:  ";
	ms.value = app->ft_ms_display;
	ms.y = 40;
	draw_overlay_str(app, &fps);
	draw_overlay_str(app, &ms);
}

void	fps_update(t_app *app)
{
	long	elapsed;

	app->fps_frames++;
	elapsed = app->last_frame_us - app->fps_update_us;
	if (elapsed < FPS_UPDATE_US)
		return ;
	app->fps_display = (int)(app->fps_frames
			* USEC_PER_SEC_DBL / elapsed);
	app->ft_ms_display = (int)(elapsed
			/ (app->fps_frames * 1000.0) + 0.5);
	app->fps_frames = 0;
	app->fps_update_us = app->last_frame_us;
}
