/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:40:51 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/01 14:21:50 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_component(char *s, int *out)
{
	if (!is_valid_component(s))
		return (0);
	*out = ft_atoi(ft_skip_spaces(s));
	return (*out >= 0 && *out <= 255);
}

static int	parse_rgb(t_rgb *dst, char *value_str)
{
	char	**p;
	int		r;
	int		g;
	int		b;

	p = ft_split(value_str, ',');
	if (!p)
		return (ft_print_error("malloc failed"));
	if (!p[0] || !p[1] || !p[2] || p[3])
	{
		free_split(p);
		return (ft_print_error("invalid RGB format"));
	}
	if (!parse_component(p[0], &r) || !parse_component(p[1], &g)
		|| !parse_component(p[2], &b))
	{
		free_split(p);
		return (ft_print_error("invalid RGB value"));
	}
	dst->r = r;
	dst->g = g;
	dst->b = b;
	free_split(p);
	return (0);
}

static int	set_color(t_rgb *dst, int *seen, char *value_str)
{
	if (*seen)
		return (ft_print_error("duplicate color identifier"));
	*seen = 1;
	return (parse_rgb(dst, value_str));
}

static int	handle_color_line(t_app *app, char *line, int *seen_f, int *seen_c)
{
	char	id;

	line = ft_skip_spaces(line);
	if (*line == '\0')
		return (0);
	id = *line;
	line++;
	line = ft_skip_spaces(line);
	if (id == 'F')
		return (set_color(&app->floor, seen_f, line));
	if (id == 'C')
		return (set_color(&app->ceiling, seen_c, line));
	return (0);
}

int	parse_colors(t_app *app, t_file *file)
{
	int	seen_f;
	int	seen_c;
	int	i;
	int	err;

	if (!app || !file)
		return (ft_print_error("internal error"));
	seen_f = 0;
	seen_c = 0;
	i = 0;
	while (i < file->line_count)
	{
		err = handle_color_line(app, file->lines[i], &seen_f, &seen_c);
		if (err != 0)
			return (1);
		i++;
	}
	return (0);
}
