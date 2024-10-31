/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:56:15 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/30 11:59:53 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit_size(unsigned int nbr)
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

static void	put_hexa(unsigned int nbr, int cas)
{
	char	*digits;

	if (nbr >= 16)
		put_hexa((nbr / 16), cas);
	if (cas == 0)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	write(1, &digits[nbr % 16], 1);
}

int	prt_hexa(unsigned int nbr, int cas)
{
	put_hexa(nbr, cas);
	return (digit_size(nbr));
}
