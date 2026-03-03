/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:12:23 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/03 18:13:01 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}			t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_tex_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_tex_paths;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_file
{
	char	*path;
	char	**lines;
	int		line_count;
	char	**map;
	int		map_height;
	int		map_width;
}			t_file;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}			t_player;

typedef struct s_app
{
	t_mlx			mlx;
	int				running;
	t_img			frame;
	t_tex_paths		tex;
	t_rgb			floor;
	t_rgb			ceiling;
	int				spawn_x;
	int				spawn_y;
	char			spawn_dir;
	t_player		player;
}					t_app;

#endif
