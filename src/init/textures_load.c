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

static char	*to_xpm42_path(const char *path)
{
	size_t	len;

	if (!path)
		return (NULL);
	len = ft_strlen(path);
	if (len < 4)
		return (NULL);
	if (ft_strncmp(path + (len - 4), ".xpm", 4) != 0)
		return (NULL);
	return (ft_strjoin(path, "42"));
}

static void	img_from_xpm(t_img *img, xpm_t *xpm)
{
	ft_bzero(img, sizeof(*img));
	img->ptr = xpm;
	img->addr = (char *)xpm->texture.pixels;
	img->w = (int)xpm->texture.width;
	img->h = (int)xpm->texture.height;
	img->bpp = 32;
	img->line_len = img->w * 4;
	img->endian = 0;
}

static int	load_single_texture(t_app *app, t_img *img, char *path)
{
	xpm_t	*xpm;
	char	*path42;
	int		fd;

	if (!app || !app->mlx.ptr || !img || !path || *path == '\0')
		return (ft_print_error("failed to load XPM texture"));
	path42 = to_xpm42_path(path);
	if (!path42)
		return (ft_print_error("failed to load XPM texture"));
	fd = open(path42, O_RDONLY);
	if (fd < 0)
	{
		free(path42);
		return (ft_print_error("missing .xpm42 (run make "
				"to generate textures)"));
	}
	close(fd);
	xpm = mlx_load_xpm42(path42);
	free(path42);
	if (!xpm)
		return (ft_print_error("failed to load XPM42 texture"));
	img_from_xpm(img, xpm);
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
