/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:35:17 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 14:38:34 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_directive_line(char *line)
{
	char	*s;

	s = ft_skip_spaces(line);
	if (*s == '\0' || *s == '\n')
		return (1);
	if ((*s == 'F' || *s == 'C')
		&& (s[1] == ' ' || s[1] == '\t' || s[1] == '\n' || s[1] == '\0'))
		return (1);
	if (ft_strncmp(s, "NO", 2) == 0 && (s[2] == ' ' || s[2] == '\t'))
		return (1);
	if (ft_strncmp(s, "SO", 2) == 0 && (s[2] == ' ' || s[2] == '\t'))
		return (1);
	if (ft_strncmp(s, "WE", 2) == 0 && (s[2] == ' ' || s[2] == '\t'))
		return (1);
	if (ft_strncmp(s, "EA", 2) == 0 && (s[2] == ' ' || s[2] == '\t'))
		return (1);
	return (0);
}

static int	validate_pre_map(t_file *file, int map_start)
{
	int	i;

	i = 0;
	while (i < map_start)
	{
		if (!is_directive_line(file->lines[i]))
			return (ft_print_error("invalid line in file"));
		i++;
	}
	return (0);
}

static int	validate_post_map(t_file *file, int map_end)
{
	int		i;
	char	*trimmed;

	i = map_end + 1;
	while (i < file->line_count)
	{
		trimmed = ft_skip_spaces(file->lines[i]);
		if (*trimmed != '\0' && *trimmed != '\n')
			return (ft_print_error("invalid map character"));
		i++;
	}
	return (0);
}

int	parse_map(t_file *file)
{
	int		start;
	int		end;

	if (!file || !file->lines)
		return (ft_print_error("internal error"));
	if (!find_map_range(file, &start, &end))
		return (ft_print_error("missing map"));
	if (!validate_map_range(file, start, end))
		return (ft_print_error("invalid map character"));
	if (validate_pre_map(file, start) != 0)
		return (1);
	if (validate_post_map(file, end) != 0)
		return (1);
	if (dup_map_block(file, start, end) != 0)
		return (1);
	return (0);
}
