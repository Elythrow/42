/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:18:41 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 17:56:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int				sign;
	unsigned long	str_int;

	sign = 1;
	str_int = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
	{
		str ++;
	}
	if (*str == '-')
		sign *= (-1);
	if (*str == '+' || *str == '-')
		str ++;
	while (ft_isdigit(*str) != 0)
	{
		str_int = str_int * 10 + *str - '0';
		str ++;
	}
	return (str_int * sign);
}
