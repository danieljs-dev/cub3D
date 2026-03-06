/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:12:49 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 14:38:54 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_line(char *s)
{
	char	*c;

	c = ft_skip_spaces(s);
	if (*c == '\0' || *c == '\n')
		return (0);
	return (*c == '0' || *c == '1' || *c == 'N'
		|| *c == 'S' || *c == 'E' || *c == 'W');
}

int	find_map_range(t_file *file, int *out_start, int *out_end)
{
	int	i;
	int	end;

	end = -1;
	i = file->line_count - 1;
	while (i >= 0)
	{
		if (is_map_line(file->lines[i]))
		{
			end = i;
			break ;
		}
		i--;
	}
	if (end < 0)
		return (0);
	*out_end = end;
	while (end >= 0 && is_map_line(file->lines[end]))
		end--;
	*out_start = end + 1;
	return (1);
}

static int	validate_map_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != ' ' && s[i] != '0' && s[i] != '1'
			&& s[i] != 'N' && s[i] != 'S' && s[i] != 'E'
			&& s[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_range(t_file *file, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (!validate_map_line(file->lines[i]))
			return (0);
		i++;
	}
	return (1);
}

int	dup_map_block(t_file *file, int start, int end)
{
	int		i;
	int		w;
	char	*line;

	file->map_height = end - start + 1;
	file->map = ft_calloc(file->map_height + 1, sizeof(char *));
	if (!file->map)
		return (ft_print_error("malloc failed"));
	file->map_width = 0;
	i = 0;
	while (start + i <= end)
	{
		line = file->lines[start + i];
		w = 0;
		while (line[w] && line[w] != '\n')
			w++;
		if (w > file->map_width)
			file->map_width = w;
		file->map[i] = ft_substr(line, 0, w);
		if (!file->map[i])
			return (ft_print_error("malloc failed"));
		i++;
	}
	return (0);
}
