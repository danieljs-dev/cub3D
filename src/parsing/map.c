/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:35:17 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/02 23:44:12 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_map(t_app *app, t_file *file)
{
	int	start;
	int	end;

	(void)app;
	if (!file || !file->lines)
		return (ft_print_error("internal error"));
	if (!find_map_range(file, &start, &end))
		return (ft_print_error("missing map"));
	if (!validate_map_range(file, start, end))
		return (ft_print_error("invalid map character"));
	if (dup_map_block(file, start, end) != 0)
		return (1);
	return (0);
}
