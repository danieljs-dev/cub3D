/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:12:23 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/04 21:46:25 by dajesus-         ###   ########.fr       */
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

typedef struct s_input
{
	int		w;
	int		a;
	int		s;
	int		d;
}			t_input;

typedef struct s_app
{
	t_mlx			mlx;
	int				running;
	t_img			frame;
	t_tex_paths		tex;
	t_rgb			floor;
	t_rgb			ceiling;
	t_file			*file;
	int				spawn_x;
	int				spawn_y;
	char			spawn_dir;
	t_player		player;
	t_input			input;
	long			last_frame_us;
}					t_app;

typedef struct s_term_ctx
{
	t_file		*file;
	int			px;
	int			py;
}				t_term_ctx;

#endif
