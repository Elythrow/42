/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:05:42 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/20 10:45:39 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_hex(unsigned int nbr, char *chars)
{
	size_t	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_put_hex(nbr / 16, chars);
		count += ft_put_hex(nbr % 16, chars);
	}
	else
		count += ft_print_c(chars[nbr]);
	return (count);
}
