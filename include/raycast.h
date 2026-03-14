/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:31:09 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/08 01:30:03 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "structs.h"

# define RAYCORE_CAM_SCALE 2.0
# define RAYCORE_CAM_SHIFT 1.0
# define RAY_HUGE 1e30

void	raycore_init(t_app *app, int screen_x, t_raycore *out);
double	ray_perp_dist(t_app *app, t_ray *ray);

void	ray_init(t_app *app, int screen_x, t_ray *ray);
void	ray_dda(t_app *app, t_ray *ray);

#endif
