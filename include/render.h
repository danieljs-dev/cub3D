/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexanfe <alexanfe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:30:11 by alexanfe          #+#    #+#             */
/*   Updated: 2026/03/14 16:30:12 by alexanfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "structs.h"

double	ray_perp_dist(t_app *app, t_ray *ray);

void	player_debug_term(t_app *app);
void	player_rotate_update(t_app *app, double dt);
void	player_update(t_app *app);
void	rotate_player(t_player *p, double angle);

void	ray_init(t_app *app, int screen_x, t_ray *ray);
void	render_walls(t_app *app);
void	raycore_init(t_app *app, int screen_x, t_raycore *out);
void	ray_dda(t_app *app, t_ray *ray);

void	free_loaded_textures(t_app *app);
void	framebuffer_destroy(t_app *app);

void	fps_update(t_app *app);
void	fps_draw(t_app *app);

int		framebuffer_init(t_app *app);
int		render_frame(t_app *app);
int		init_loaded_textures(t_app *app);
int		player_init(t_app *app);
int		player_move(t_app *app, double dx, double dy);
int		on_keydown(int keycode, void *param);
int		on_keyup(int keycode, void *param);
int		on_destroy(void *param);

#endif
