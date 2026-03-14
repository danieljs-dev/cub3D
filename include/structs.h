/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:12:23 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/14 16:30:18 by alexanfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define NUM_WALL_TEX 4

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
	char	**map;
	int		line_count;
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
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}			t_ray;

typedef struct s_tex_col
{
	double	wall_x;
	double	tex_step;
	double	tex_pos;
	int		x;
	int		start;
	int		end;
	int		line_h;
	int		tex_idx;
	int		bpp;
	int		tex_x;
}			t_tex_col;

typedef enum e_wall_dir
{
	TEX_NO,
	TEX_SO,
	TEX_WE,
	TEX_EA
}			t_wall_dir;

typedef struct s_app
{
	t_mlx			mlx;
	t_img			frame;
	t_img			wall_text[NUM_WALL_TEX];
	t_file			*file;
	t_player		player;
	t_tex_paths		tex;
	t_rgb			floor;
	t_rgb			ceiling;
	t_input			input;
	long			last_frame_us;
	long			fps_update_us;
	int				running;
	int				spawn_x;
	int				spawn_y;
	int				fps_frames;
	int				fps_display;
	int				ft_ms_display;
	char			spawn_dir;
}					t_app;

typedef struct s_term_ctx
{
	t_file	*file;
	int		px;
	int		py;
	int		lx;
	int		ly;
}				t_term_ctx;

#endif
