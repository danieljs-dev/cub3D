/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexanfe <alexanfe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:29:49 by alexanfe          #+#    #+#             */
/*   Updated: 2026/03/14 16:29:54 by alexanfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/* ---- window ---- */
# define CUB3D_WIN_TITLE "cub3D"
# define CUB3D_WIN_W 800
# define CUB3D_WIN_H 600

/* ---- key codes ---- */
# define XK_ESCAPE 65307
# define XK_W 119
# define XK_A 97
# define XK_S 115
# define XK_D 100
# define XK_LEFT 65361
# define XK_RIGHT 65363

/* ---- player ---- */
# define PLAYER_MOVE_SPEED 3.0
# define PLAYER_MAX_DT 0.05
# define PLAYER_COLLISION_RADIUS 0.2
# define ROT_SPEED 1.5
# define CAMERA_PLANE_LEN 0.66
# define PLAYER_DEFAULT_DT 0.0166666666666667

/* ---- raycasting ---- */
# define RAYCORE_CAM_SCALE 2.0
# define RAYCORE_CAM_SHIFT 1.0
# define RAY_HUGE 1e30

/* ---- timing / fps ---- */
# define USEC_PER_SEC 1000000L
# define USEC_PER_SEC_DBL 1000000.0
# define FPS_UPDATE_US 500000L

/* ---- debug ---- */
# define PLAYER_TERM_DEBUG 1
# define FPS_DISPLAY 1

# define TERM_RESET "\033[0m"
# define TERM_WALL "\033[44m"
# define TERM_FLOOR "\033[42m"
# define TERM_VOID "\033[40m"
# define TERM_PLAYER "\033[43m"
# define TERM_LOOK "\033[45m"

#endif
