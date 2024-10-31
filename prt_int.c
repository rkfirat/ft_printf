/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:44:45 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/30 11:51:11 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digits_size(int nbr)
{
	size_t	digits;

	digits = 0;
	if (nbr <= 0)
		digits++;
	while (nbr != 0)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static void	put_int(int nbr)
{
	char	*digits;

	digits = "0123456789";
	if (nbr > 9)
		put_int(nbr / 10);
	write(1, &digits[nbr % 10], 1);
}

int	prt_int(int nbr)
{
	int	len;

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	len = digits_size(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	put_int(nbr);
	return (len);
}
