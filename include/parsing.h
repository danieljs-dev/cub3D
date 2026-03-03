/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:49:50 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 16:56:05 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

int		ft_print_error(const char *msg);
int		ft_has_cub_extension(const char *path);
int		ft_has_xpm_extension(const char *path);
int		parse_cub_file(int argc, char **argv, t_file *file);
void	free_file(t_file *file);

int		parse_textures(t_app *app, t_file *file);
void	free_textures(t_tex_paths *tex);
int		parse_colors(t_app *app, t_file *file);
int		parse_map(t_app *app, t_file *file);

int		find_map_range(t_file *file, int *out_start, int *out_end);
int		validate_map_range(t_file *file, int start, int end);
int		dup_map_block(t_file *file, int start, int end);
int		validate_map_closed(t_file *file);
int		validate_player_spawn(t_app *app, t_file *file);

void	free_split(char **parts);
int		is_valid_component(char *s);

#endif
