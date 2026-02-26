/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:22:53 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/26 14:24:37 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error_code
{
	ERR_NULL,
	ERR_NIL,
	ERR_UNKNOWN,
	ERR_COUNT
}	t_error_code;

const char	*get_error_message(t_error_code code);

#endif
