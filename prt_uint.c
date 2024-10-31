/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:35:18 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/30 11:51:39 by rfirat           ###   ########.fr       */
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
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static void	put_digit(unsigned int nbr)
{
	char	*digits;

	digits = "0123456789";
	if (nbr > 9)
		put_digit(nbr / 10);
	write(1, &digits[nbr % 10], 1);
}

int	prt_uint(unsigned int nbr)
{
	put_digit(nbr);
	return (digit_size(nbr));
}
