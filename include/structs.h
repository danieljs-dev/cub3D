/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:12:23 by dajesus-          #+#    #+#             */
/*   Updated: 2026/02/25 23:41:15 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_app
{
	t_mlx	mlx;
	int		running;
}			t_app;

#endif
