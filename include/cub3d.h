/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:05:13 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/11 23:21:33 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"

# include "structs.h"
# include "events.h"
# include "parsing.h"
# include "player.h"
# include "keys.h"
# include "raycast.h"

# define CUB3D_WIN_TITLE "cub3D"
# define CUB3D_WIN_W 800
# define CUB3D_WIN_H 600

int		framebuffer_init(t_app *app);
void	framebuffer_destroy(t_app *app);
int		render_frame(t_app *app);
void	render_walls(t_app *app);
void	fps_update(t_app *app);
void	fps_draw(t_app *app);
int		init_loaded_textures(t_app *app);
void	free_loaded_textures(t_app *app);

#endif
