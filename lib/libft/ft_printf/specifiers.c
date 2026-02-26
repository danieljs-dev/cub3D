/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:04:21 by dajesus-          #+#    #+#             */
/*   Updated: 2024/12/17 21:18:56 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_func	find_function(char specifier)
{
	int							i;
	static const t_specifier	specifiers[9] = {
	{'c', print_char},
	{'s', print_string},
	{'p', print_pointer},
	{'d', print_int},
	{'i', print_int},
	{'u', print_unsigned_dec},
	{'x', print_unsigned_lower_hex},
	{'X', print_unsigned_upper_hex},
	{'\0', NULL}
	};

	i = 0;
	while (specifiers[i].specifier != '\0')
	{
		if (specifiers[i].specifier == specifier)
			return (specifiers[i].func);
		i++;
	}
	return (NULL);
}
