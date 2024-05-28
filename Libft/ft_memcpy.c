/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:44:17 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 16:52:55 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	str_src = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i ++;
	}
	return (dest);
}
