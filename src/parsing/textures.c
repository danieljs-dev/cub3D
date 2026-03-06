/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:46:26 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 02:17:34 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	match_id(char *s, const char *id)
{
	s = ft_skip_spaces(s);
	if (ft_strncmp(s, id, 2) != 0)
		return (0);
	if (s[2] != ' ' && s[2] != '\t')
		return (0);
	return (1);
}

static int	set_path(char **dst, char *src)
{
	int	fd;

	if (*dst)
		return (ft_print_error("duplicate texture identifier"));
	src = ft_skip_spaces(src);
	src += 2;
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
	if (match_id(line, "NO"))
		return (set_path(&app->tex.no, line));
	if (match_id(line, "SO"))
		return (set_path(&app->tex.so, line));
	if (match_id(line, "WE"))
		return (set_path(&app->tex.we, line));
	if (match_id(line, "EA"))
		return (set_path(&app->tex.ea, line));
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
