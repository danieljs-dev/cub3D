/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:10:00 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/06 01:52:49 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "structs.h"

# define PLAYER_MOVE_SPEED 3.0
# define PLAYER_MAX_DT 0.05
# define PLAYER_COLLISION_RADIUS 0.2
# define ROT_SPEED 0.05

# define PLAYER_DEFAULT_DT 0.0166666666666667 // (1.0 / 60.0)

# define USEC_PER_SEC 1000000L
# define USEC_PER_SEC_DBL 1000000.0

# define PLAYER_TERM_DEBUG 1

# define TERM_RESET "\033[0m"
# define TERM_WALL "\033[44m"
# define TERM_FLOOR "\033[42m"
# define TERM_VOID "\033[40m"
# define TERM_PLAYER "\033[43m"

int		player_init(t_app *app);
void	player_update(t_app *app);
void	rotate_player(t_player *p, double angle);
int		player_move(t_app *app, double dx, double dy);
void	player_debug_term(t_app *app);

#endif
