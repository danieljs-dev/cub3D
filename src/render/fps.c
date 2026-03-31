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

static void	draw_overlay_str(t_app *app, void **slot,
						const char *prefix, int value, int y)
{
	char	*num;
	char	*str;
	mlx_image_t	*img;

	if (!app || !app->mlx.ptr || !slot)
		return ;
	if (*slot)
	{
		mlx_delete_image(app->mlx.ptr, *slot);
		*slot = NULL;
	}
	num = ft_itoa(value);
	if (!num)
		return ;
	str = ft_strjoin(prefix, num);
	free(num);
	if (!str)
		return ;
	img = mlx_put_string(app->mlx.ptr, str, 10, y);
	free(str);
	if (!img)
		return ;
	if (img->count > 0)
		mlx_set_instance_depth(&img->instances[0], 10);
	*slot = img;
}

void	fps_draw(t_app *app)
{
	draw_overlay_str(app, &app->fps_img, "FPS: ", app->fps_display, 20);
	draw_overlay_str(app, &app->ms_img, "MS:  ", app->ft_ms_display, 40);
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
