/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:02:28 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/25 23:46:22 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	app_destroy(t_app *app)
{
	if (!app)
		return ;
	if (app->mlx.ptr && app->mlx.win)
		mlx_destroy_window(app->mlx.ptr, app->mlx.win);
	if (app->mlx.ptr)
	{
		mlx_destroy_display(app->mlx.ptr);
		free(app->mlx.ptr);
		app->mlx.ptr = NULL;
	}
}

static int	app_init(t_app *app)
{
	ft_bzero(app, sizeof(*app));
	app->running = 1;
	app->mlx.ptr = mlx_init();
	if (!app->mlx.ptr)
		return (0);
	app->mlx.win = mlx_new_window(app->mlx.ptr, CUB3D_WIN_W, CUB3D_WIN_H,
			CUB3D_WIN_TITLE);
	if (!app->mlx.win)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_app	app;

	(void)argv;
	(void)argc;
	if (!app_init(&app))
	{
		app_destroy(&app);
		return (1);
	}
	mlx_hook(app.mlx.win, 2, 1L << 0, on_keydown, &app);
	mlx_hook(app.mlx.win, 17, 0, on_destroy, &app);
	mlx_loop(app.mlx.ptr);
	app_destroy(&app);
	return (0);
}
