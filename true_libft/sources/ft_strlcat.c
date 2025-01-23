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
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	i = ft_strlen(dest);
	if (size == 0)
		return (size_src + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < size_dest)
		return (size_src + size);
	return (size_dest + size_src);
}
