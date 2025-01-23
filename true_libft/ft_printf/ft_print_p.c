/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:58:03 by gbazin            #+#    #+#             */
/*   Updated: 2024/12/04 17:12:10 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long adr)
{
	int	count;

	if ((void *)adr == NULL)
		return (ft_print_s("(nil)"));
	count = 0;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(adr);
	if (count < -1)
		return (-1);
	return (count);
}
