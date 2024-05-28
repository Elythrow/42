/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:02 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 16:14:13 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	s_dest;
	unsigned int	s_src;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	s_dest = ft_strlen(dest);
	s_src = ft_strlen(src);
	i = ft_strlen(dest);
	if (size == 0)
		return (s_src + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < s_dest)
		return (s_src + size);
	return (s_dest + s_src);
}
