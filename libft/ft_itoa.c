/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:52:07 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 19:07:31 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_size(int number)
{
	unsigned int	size;

	size = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		size += 1;
	while (number != 0)
	{
		size ++;
		number /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned long	number;
	int				length;

	length = ft_number_size(n);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		number = -(long)n;
	}
	else
		number = n;
	if (number == 0)
		str[0] = '0';
	str[length] = '\0';
	while (number != 0)
	{
		str[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (str);
}
