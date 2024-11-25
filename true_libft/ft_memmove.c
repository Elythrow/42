/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:30:45 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 16:53:36 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	str_src = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	if (str_dest > str_src)
	{
		while (n)
		{
			n --;
			str_dest[n] = str_src[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
