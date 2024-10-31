/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:37:48 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/30 12:15:43 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (format == 's')
		return (prt_str(va_arg(args, char *)));
	else if (format == 'p')
		return (prt_ptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (prt_int(va_arg(args, int)));
	else if (format == 'u')
		return (prt_uint(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (prt_hexa(va_arg(args, unsigned int), format == 'x'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	if (!str)
		return (0);
	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_length += (ft_formats(args, str[i]));
		}
		else
			print_length += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (print_length);
}
