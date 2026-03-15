/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:49:50 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/14 16:30:06 by alexanfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

void	free_file(t_file *file);
void	free_textures(t_tex_paths *tex);
void	free_split(char **parts);

int		ft_print_error(const char *msg);
int		ft_has_cub_extension(const char *path);
int		ft_has_xpm_extension(const char *path);

int		parse_cub_file(int argc, char **argv, t_file *file);
int		parse_textures(t_app *app, t_file *file);
int		parse_colors(t_app *app, t_file *file);
int		parse_map(t_file *file);

int		validate_map_range(t_file *file, int start, int end);
int		validate_map_closed(t_file *file);
int		validate_player_spawn(t_app *app, t_file *file);

int		find_map_range(t_file *file, int *out_start, int *out_end);
int		dup_map_block(t_file *file, int start, int end);
int		is_valid_component(char *s);
int		map_cell_at(t_file *file, int x, int y);

#endif
