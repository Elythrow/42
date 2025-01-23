/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:57:47 by gbazin            #+#    #+#             */
/*   Updated: 2024/12/04 17:12:01 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nb < 0)
	{
		count += ft_print_c('-');
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else
	{
		if (nb >= 10)
		{
			count += ft_putnbr(nb / 10);
			count += ft_putnbr(nb % 10);
		}
		else
			count += ft_print_c(nb + 48);
	}
	if (count < 0)
		return (-1);
	return (count);
}
