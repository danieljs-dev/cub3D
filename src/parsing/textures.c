/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:46:26 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/28 02:00:54 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_id(const char *s, const char *id)
{
	if (!s || !id)
		return (0);
	return (ft_strncmp(s, id, 2) == 0 && (s[2] == ' ' || s[2] == '\t'));
}

static int	set_path(char **dst, const char *src)
{
	int	fd;

	if (*dst)
		return (ft_print_error("duplicate texture identifier"));
	*dst = ft_strtrim(src, " \t\n");
	if (!*dst || **dst == '\0')
		return (ft_print_error("invalid texture path"));
	if (!ft_has_xpm_extension(*dst))
	{
		free(*dst);
		*dst = NULL;
		return (ft_print_error("invalid texture extension (expected .xpm)"));
	}
	fd = open(*dst, O_RDONLY);
	if (fd < 0)
		return (ft_print_error("texture path not accessible"));
	close(fd);
	return (0);
}

static int	handle_line(t_app *app, char *line)
{
	if (is_id(line, "NO"))
		return (set_path(&app->tex.no, line + 2));
	if (is_id(line, "SO"))
		return (set_path(&app->tex.so, line + 2));
	if (is_id(line, "WE"))
		return (set_path(&app->tex.we, line + 2));
	if (is_id(line, "EA"))
		return (set_path(&app->tex.ea, line + 2));
	return (0);
}

void	free_textures(t_tex_paths *tex)
{
	if (!tex)
		return ;
	free(tex->no);
	free(tex->so);
	free(tex->we);
	free(tex->ea);
	tex->no = NULL;
	tex->so = NULL;
	tex->we = NULL;
	tex->ea = NULL;
}

int	parse_textures(t_app *app, t_file *file)
{
	int	i;

	if (!app || !file)
		return (ft_print_error("internal error"));
	ft_bzero(&app->tex, sizeof(app->tex));
	i = 0;
	while (i < file->line_count)
	{
		if (handle_line(app, file->lines[i]) != 0)
			return (1);
		i++;
	}
	if (!app->tex.no || !app->tex.so || !app->tex.we || !app->tex.ea)
		return (ft_print_error("missing texture identifier(s)"));
	return (0);
}
