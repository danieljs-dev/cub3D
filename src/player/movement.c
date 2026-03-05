/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:28:15 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/04 21:46:25 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		player_move(t_app *app, double dx, double dy);

static double	frame_dt(t_app *app)
{
	struct timeval	tv;
	long			now;
	double			dt;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * USEC_PER_SEC) + tv.tv_usec;
	if (app->last_frame_us == 0)
	{
		app->last_frame_us = now;
		return (PLAYER_DEFAULT_DT);
	}
	dt = (double)(now - app->last_frame_us) / USEC_PER_SEC_DBL;
	app->last_frame_us = now;
	if (dt < 0.0)
		return (0.0);
	if (dt > PLAYER_MAX_DT)
		return (PLAYER_MAX_DT);
	return (dt);
}

static void	add_vec(double *x, double *y, double ax, double ay)
{
	*x += ax;
	*y += ay;
}

static void	move_vec(t_app *app, double *out_x, double *out_y)
{
	double	sx;
	double	sy;

	*out_x = 0.0;
	*out_y = 0.0;
	sx = -app->player.dir_y;
	sy = app->player.dir_x;
	if (app->input.w)
		add_vec(out_x, out_y, app->player.dir_x, app->player.dir_y);
	if (app->input.s)
		add_vec(out_x, out_y, -app->player.dir_x, -app->player.dir_y);
	if (app->input.a)
		add_vec(out_x, out_y, -sx, -sy);
	if (app->input.d)
		add_vec(out_x, out_y, sx, sy);
}

static int	move_step(t_app *app, double dt)
{
	double	mx;
	double	my;
	double	len;

	move_vec(app, &mx, &my);
	if (mx == 0.0 && my == 0.0)
		return (0);
	len = sqrt((mx * mx) + (my * my));
	if (len <= 0.0)
		return (0);
	mx /= len;
	my /= len;
	return (player_move(app, mx * PLAYER_MOVE_SPEED * dt,
			my * PLAYER_MOVE_SPEED * dt));
}

void	player_update(t_app *app)
{
	double	dt;
	int		moved;

	if (!app)
		return ;
	dt = frame_dt(app);
	if (dt <= 0.0)
		return ;
	moved = move_step(app, dt);
	if (PLAYER_TERM_DEBUG && moved)
		player_debug_term(app);
}
