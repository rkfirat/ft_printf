/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:59 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/30 12:10:13 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit_size(unsigned long nbr)
{
	size_t	digits;

	digits = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		digits++;
	}
	return (digits);
}

static void	put_ptr(unsigned long addr)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (addr >= 16)
		put_ptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}

int	prt_ptr(void *addr)
{
	write(1, "0x", 2);
	put_ptr(((unsigned long)addr));
	return (digit_size((unsigned long)addr) + 2);
}
