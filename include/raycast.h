/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20∶31∶09 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/06 22:49:25 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "structs.h"

# define RAYCORE_CAM_SCALE 2.0
# define RAYCORE_CAM_SHIFT 1.0

void	raycore_init(t_app *app, int screen_x, t_raycore *out);

#endif
