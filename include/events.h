/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:17:26 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/05 23:00:03 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "structs.h"

#ifndef XK_ESCAPE
# define XK_ESCAPE 65307
#endif

#ifndef XK_LEFT
# define XK_LEFT 65361
#endif

#ifndef XK_RIGHT
# define XK_RIGHT 65363
#endif

# define ROT_SPEED 0.05

int	on_keydown(int keycode, void *param);
int	on_keyup(int keycode, void *param);
int	on_destroy(void *param);

#endif
