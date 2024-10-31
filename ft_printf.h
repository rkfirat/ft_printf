/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:05:31 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/30 09:30:23 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	prt_str(char const *str);
int	prt_ptr(void *addr);
int	prt_int(int nbr);
int	prt_uint(unsigned int nbr);
int	prt_hexa(unsigned int nbr, int cas);

#endif