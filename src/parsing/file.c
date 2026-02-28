/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:49:50 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/27 21:55:06 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**append_line(char **old, int count, char *line)
{
	char	**tmp;
	int		i;

	tmp = ft_calloc(count + 2, sizeof(char *));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tmp[i] = old[i];
		i++;
	}
	tmp[count] = line;
	free(old);
	return (tmp);
}

static int	read_all_lines(int fd, t_file *file)
{
	char	*line;

	file->lines = NULL;
	file->line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		file->lines = append_line(file->lines, file->line_count, line);
		if (!file->lines)
		{
			free(line);
			return (0);
		}
		file->line_count++;
	}
	return (1);
}

static int	load_file(const char *path, t_file *file)
{
	int	fd;

	file->path = (char *)path;
	file->lines = NULL;
	file->line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_print_error("cannot open map file"));
	if (!read_all_lines(fd, file))
	{
		close(fd);
		return (ft_print_error("failed to read map file"));
	}
	close(fd);
	return (0);
}

void	free_file(t_file *file)
{
	int	i;

	if (!file || !file->lines)
		return ;
	i = 0;
	while (i < file->line_count)
	{
		free(file->lines[i]);
		i++;
	}
	free(file->lines);
	file->lines = NULL;
	file->line_count = 0;
}

int	parse_cub_file(int argc, char **argv, t_file *file)
{
	if (argc != 2)
		return (ft_print_error("usage: ./cub3D map.cub"));
	if (!ft_has_cub_extension(argv[1]))
		return (ft_print_error("invalid map extension (expected .cub)"));
	if (load_file(argv[1], file) != 0)
		return (1);
	return (0);
}
