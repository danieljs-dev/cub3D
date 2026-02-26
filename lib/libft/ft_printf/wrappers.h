/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:59:40 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/26 14:26:26 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include <stdarg.h>

int	print_char(va_list args, int fd);
int	print_string(va_list args, int fd);
int	print_pointer(va_list args, int fd);
int	print_int(va_list args, int fd);
int	print_unsigned_dec(va_list args, int fd);
int	print_unsigned_lower_hex(va_list args, int fd);
int	print_unsigned_upper_hex(va_list args, int fd);

#endif
