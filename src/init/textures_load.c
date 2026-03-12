/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:58:45 by vinda-si          #+#    #+#             */
/*   Updated: 2026/03/11 23:09:23 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_img(t_img *img)
{
	if (!img)
		return ;
	ft_bzero(img, sizeof(*img));
}

static int	load_single_texture(t_app *app, t_img *img, char *path)
{
	if (!app || !app->mlx.ptr || !img || !path || *path == '\0')
		return (ft_print_error("Failed to load XPM texture"));
	clear_img(img);
	img->ptr = mlx_xpm_file_to_image(app->mlx.ptr, path, &img->w, &img->h);
	if (!img->ptr)
		return (ft_print_error("Failed to load XPM texture"));
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(app->mlx.ptr, img->ptr);
		clear_img(img);
		return (ft_print_error("Failed to get texture data address"));
	}
	return (0);
}

static char	*get_tex_path(t_app *app, int index)
{
	if (index == TEX_NO)
		return (app->tex.no);
	if (index == TEX_SO)
		return (app->tex.so);
	if (index == TEX_WE)
		return (app->tex.we);
	return (app->tex.ea);
}

int	init_loaded_textures(t_app *app)
{
	int	i;

	if (!app)
		return (1);
	ft_bzero(app->wall_text, sizeof(app->wall_text));
	i = 0;
	while (i < NUM_WALL_TEX)
	{
		if (load_single_texture(app, &app->wall_text[i],
				get_tex_path(app, i)) != 0)
			return (free_loaded_textures(app), 1);
		i++;
	}
	return (0);
}
