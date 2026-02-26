/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:00:45 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/26 14:25:18 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list args, int fd)
{
	uintptr_t		ptr_value;
	int				count;
	char			*error_message;

	count = 0;
	error_message = (char *)get_error_message(ERR_NIL);
	ptr_value = (uintptr_t)va_arg(args, void *);
	if (ptr_value == 0)
	{
		ft_putstr_fd(error_message, fd);
		return (ft_strlen(error_message));
	}
	ft_putstr_fd("0x", fd);
	count += 2;
	count += ft_putunsigned_hex_fd(ptr_value, HEX_LOWER, fd);
	return (count);
}
