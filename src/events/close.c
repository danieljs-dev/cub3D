/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:20:24 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/04 21:46:25 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	on_destroy(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app || !app->mlx.ptr)
		return (0);
	app->running = 0;
	mlx_loop_end(app->mlx.ptr);
	return (0);
}
