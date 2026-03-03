/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:02:28 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 16:56:14 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	app_destroy(t_app *app)
{
	if (!app)
		return ;
	framebuffer_destroy(app);
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
	if (!framebuffer_init(app))
		return (0);
	return (1);
}

static int	parse_all(t_app *tmp, t_file *file)
{
	if (parse_textures(tmp, file) != 0)
		return (1);
	if (parse_colors(tmp, file) != 0)
		return (1);
	if (parse_map(tmp, file) != 0)
		return (1);
	if (validate_map_closed(file) != 0)
		return (1);
	if (validate_player_spawn(tmp, file) != 0)
		return (1);
	return (0);
}

static int	check_errors(int argc, char **argv, t_file *file)
{
	t_app	tmp;

	ft_bzero(&tmp, sizeof(tmp));
	if (parse_cub_file(argc, argv, file) != 0)
		return (1);
	if (parse_all(&tmp, file) != 0)
	{
		free_textures(&tmp.tex);
		free_file(file);
		return (1);
	}
	free_textures(&tmp.tex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;
	t_file	file;

	if (check_errors(argc, argv, &file) != 0)
		return (1);
	if (!app_init(&app))
	{
		free_file(&file);
		app_destroy(&app);
		return (1);
	}
	mlx_hook(app.mlx.win, 2, 1L << 0, on_keydown, &app);
	mlx_hook(app.mlx.win, 17, 0, on_destroy, &app);
	mlx_loop_hook(app.mlx.ptr, render_frame, &app);
	mlx_loop(app.mlx.ptr);
	free_file(&file);
	app_destroy(&app);
	return (0);
}
