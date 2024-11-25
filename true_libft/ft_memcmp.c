/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:30:39 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 16:51:46 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (str1[i] == str2[i])
			i ++;
		else
			break ;
	}
	return (str1[i] - str2[i]);
}
