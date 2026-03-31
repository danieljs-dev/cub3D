/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:02:28 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/11 23:24:35 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	app_destroy(t_app *app)
{
	if (!app)
		return ;
	framebuffer_destroy(app);
	free_loaded_textures(app);
	if (app->mlx.ptr && app->fps_img)
		mlx_delete_image(app->mlx.ptr, app->fps_img);
	if (app->mlx.ptr && app->ms_img)
		mlx_delete_image(app->mlx.ptr, app->ms_img);
	app->fps_img = NULL;
	app->ms_img = NULL;
	if (app->mlx.ptr)
		mlx_terminate(app->mlx.ptr);
	app->mlx.ptr = NULL;
}

static int	app_init(t_app *app)
{
	int32_t	inst;

	app->running = 1;
	app->mlx.ptr = mlx_init(CUB3D_WIN_W, CUB3D_WIN_H, CUB3D_WIN_TITLE, true);
	if (!app->mlx.ptr)
		return (0);
	app->mlx.win = NULL;
	if (!framebuffer_init(app))
		return (0);
	inst = mlx_image_to_window(app->mlx.ptr, app->frame.ptr, 0, 0);
	if (inst < 0)
		return (0);
	if (init_loaded_textures(app) != 0)
		return (0);
	return (1);
}

static void	loop_hook(void *param)
{
	render_frame((t_app *)param);
}

static int	parse_setup(t_app *app, t_file *file, int argc, char **argv)
{
	ft_bzero(app, sizeof(*app));
	if (parse_cub_file(argc, argv, file) != 0)
		return (1);
	if (parse_textures(app, file) != 0
		|| parse_colors(app, file) != 0
		|| parse_map(file) != 0
		|| validate_map_closed(file) != 0
		|| validate_player_spawn(app, file) != 0
		|| player_init(app) != 0)
	{
		free_textures(&app->tex);
		free_file(file);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;
	t_file	file;

	if (parse_setup(&app, &file, argc, argv) != 0)
		return (1);
	app.file = &file;
	if (!app_init(&app))
	{
		free_textures(&app.tex);
		free_file(&file);
		app_destroy(&app);
		return (1);
	}
	mlx_key_hook(app.mlx.ptr, on_key, &app);
	mlx_close_hook(app.mlx.ptr, on_destroy, &app);
	mlx_loop_hook(app.mlx.ptr, loop_hook, &app);
	if (PLAYER_TERM_DEBUG)
		player_debug_term(&app);
	mlx_loop(app.mlx.ptr);
	free_textures(&app.tex);
	free_file(&file);
	app_destroy(&app);
	return (0);
}
