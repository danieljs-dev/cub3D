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

#include "../../include/cub3d.h"

int	on_keydown(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app)
		return (0);
	if (keycode == XK_ESCAPE)
		return (on_destroy(param));
	if (keycode == XK_LEFT)
		app->input.left = 1;
	else if (keycode == XK_RIGHT)
		app->input.right = 1;
	if (keycode == XK_W)
		app->input.w = 1;
	else if (keycode == XK_A)
		app->input.a = 1;
	else if (keycode == XK_S)
		app->input.s = 1;
	else if (keycode == XK_D)
		app->input.d = 1;
	return (0);
}

int	on_keyup(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app)
		return (0);
	if (keycode == XK_LEFT)
		app->input.left = 0;
	else if (keycode == XK_RIGHT)
		app->input.right = 0;
	else if (keycode == XK_W)
		app->input.w = 0;
	else if (keycode == XK_A)
		app->input.a = 0;
	else if (keycode == XK_S)
		app->input.s = 0;
	else if (keycode == XK_D)
		app->input.d = 0;
	return (0);
}
