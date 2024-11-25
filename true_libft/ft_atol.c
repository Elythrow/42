/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:56:48 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 17:58:27 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char const *str)
{
	int				sign;
	unsigned long	str_long;

	sign = 1;
	str_long = 0;
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
		str_long = str_long * 10 + *str - '0';
		str ++;
	}
	return (str_long * sign);
}
