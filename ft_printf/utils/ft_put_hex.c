/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:05:42 by gbazin            #+#    #+#             */
/*   Updated: 2024/12/04 17:12:04 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int nbr, char *chars)
{
	int	count;

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
