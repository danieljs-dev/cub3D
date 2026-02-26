/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:05:13 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/26 20:12:07 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"

# include "structs.h"
# include "events.h"

# define CUB3D_WIN_TITLE "cub3D"
# define CUB3D_WIN_W 800
# define CUB3D_WIN_H 600

int		framebuffer_init(t_app *app);
void	framebuffer_destroy(t_app *app);

#endif
