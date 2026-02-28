/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:49:50 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/27 21:55:26 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

typedef struct s_file
{
	char	*path;
	char	**lines;
	int		line_count;
}			t_file;

int		ft_print_error(const char *msg);
int		ft_has_cub_extension(const char *path);
int		parse_cub_file(int argc, char **argv, t_file *file);
void	free_file(t_file *file);

#endif
