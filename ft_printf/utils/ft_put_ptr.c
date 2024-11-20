/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:05:19 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/20 10:45:14 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_ptr(uintptr_t nbr)
{
	char	*chars;
	size_t	count;

	chars = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		count += ft_put_ptr(nbr / 16);
		count += ft_put_ptr(nbr % 16);
	}
	else
		count += ft_print_c(chars[nbr]);
	if (count < 0)
		return (-1);
	return (count);
}
