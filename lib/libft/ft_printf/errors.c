/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:26:52 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/26 14:24:29 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

const char	*get_error_message(t_error_code code)
{
	static const char	*error_messages[ERR_COUNT] = {
		"(null)",
		"(nil)",
		"Unknown error."
	};

	if (code >= ERR_NULL && code < ERR_COUNT)
	{
		return (error_messages[code]);
	}
	return (error_messages[ERR_UNKNOWN]);
}
