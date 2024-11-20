/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:58:06 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/20 11:08:37 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int nbr)
{
	size_t	count;

	count = 0;
	count += ft_putnbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}
