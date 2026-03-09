/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:12:23 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/08 21:55:18 by dajesus-         ###   ########.fr       */
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
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_input
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}			t_input;

typedef struct s_raycore
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
}			t_raycore;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}			t_ray;

typedef struct s_draw
{
	int				x;
	int				start;
	int				end;
	unsigned int	color;
}					t_draw;

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
	int			lx;
	int			ly;
}				t_term_ctx;

#endif
