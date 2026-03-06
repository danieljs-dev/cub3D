/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:39:28 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/06 02:43:41 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	facing_char(t_player *p)
{
	double	ax;
	double	ay;

	ax = p->dir_x;
	ay = p->dir_y;
	if (ax < 0.0)
		ax = -ax;
	if (ay < 0.0)
		ay = -ay;
	if (ax >= ay)
		return ('E' + (p->dir_x < 0.0) * ('W' - 'E'));
	return ('S' + (p->dir_y < 0.0) * ('N' - 'S'));
}

static int	cell_at(t_file *file, int x, int y)
{
	int	len;

	if (!file || !file->map || y < 0 || y >= file->map_height)
		return (' ');
	len = (int)ft_strlen(file->map[y]);
	if (x < 0 || x >= len)
		return (' ');
	return (file->map[y][x]);
}

static void	put_cell(const char *bg)
{
	write(1, bg, ft_strlen(bg));
	write(1, "  ", 2);
	write(1, TERM_RESET, ft_strlen(TERM_RESET));
}

static void	print_row(t_term_ctx *ctx, int y)
{
	int	x;
	int	c;

	x = 0;
	while (x < ctx->file->map_width)
	{
		if (y == ctx->py && x == ctx->px)
			put_cell(TERM_PLAYER);
		else if (y == ctx->ly && x == ctx->lx)
			put_cell(TERM_LOOK);
		else
		{
			c = cell_at(ctx->file, x, y);
			if (c == '1')
				put_cell(TERM_WALL);
			else if (c == '0')
				put_cell(TERM_FLOOR);
			else
				put_cell(TERM_VOID);
		}
		x++;
	}
	write(1, "\n", 1);
}

void	player_debug_term(t_app *app)
{
	t_term_ctx	ctx;
	int			y;
	char		f;

	if (!app || !app->file || !app->file->map)
		return ;
	ctx.px = (int)app->player.x;
	ctx.py = (int)app->player.y;
	ctx.file = app->file;
	f = facing_char(&app->player);
	ctx.lx = ctx.px + (f == 'E') - (f == 'W');
	ctx.ly = ctx.py + (f == 'S') - (f == 'N');
	write(1, "\033[H\033[J", 6);
	y = 0;
	while (y < app->file->map_height)
	{
		print_row(&ctx, y);
		y++;
	}
	ft_printf("Facing: %c\n", f);
}
