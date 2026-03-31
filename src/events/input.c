/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:38:54 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/06 02:43:47 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_input_key(t_app *app, keys_t key, int pressed)
{
	if (key == XK_LEFT)
		app->input.left = pressed;
	else if (key == XK_RIGHT)
		app->input.right = pressed;
	else if (key == XK_W)
		app->input.w = pressed;
	else if (key == XK_A)
		app->input.a = pressed;
	else if (key == XK_S)
		app->input.s = pressed;
	else if (key == XK_D)
		app->input.d = pressed;
}

void	on_key(mlx_key_data_t keydata, void *param)
{
	t_app	*app;
	int		pressed;

	app = (t_app *)param;
	if (!app)
		return ;
	if (keydata.key == XK_ESCAPE && keydata.action == MLX_PRESS)
	{
		on_destroy(param);
		return ;
	}
	pressed = 0;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		pressed = 1;
	if (keydata.action == MLX_RELEASE)
		pressed = 0;
	set_input_key(app, keydata.key, pressed);
}
