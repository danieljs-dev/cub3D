/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:20:24 by dajesus-          #+#    #+#             */
/*   Updated: 2026/03/11 23:16:51 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	free_loaded_textures(t_app *app)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (app->wall_text[i].ptr)
		{
			mlx_destroy_image(app->mlx.ptr, app->wall_text[i].ptr);
			app->wall_text[i].ptr = NULL;
		}
		i++;
	}
}
