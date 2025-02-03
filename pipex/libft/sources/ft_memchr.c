/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:30:36 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 16:50:36 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str ++;
		n --;
	}
	return (NULL);
}
