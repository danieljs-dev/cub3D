/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:20:24 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/25 23:43:35 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#ifndef XK_ESCAPE
# define XK_ESCAPE 65307
#endif

int	on_destroy(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app || !app->mlx.ptr)
		return (0);
	app->running = 0;
	mlx_loop_end(app->mlx.ptr);
	return (0);
}

int	on_keydown(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app)
		return (0);
	if (keycode == XK_ESCAPE)
		return (on_destroy(param));
	return (0);
}
