/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:48 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 16:58:43 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (str2[0] == 0)
		return ((char *)str1);
	i = 0;
	while (str1[i] && i < len)
	{
		j = 0;
		while (str2[j] == str1[i + j] && str1[i + j] && i + j < len)
		{
			if (str2[j + 1] == '\0')
				return ((char *)&str1[i]);
			j ++;
		}
		i ++;
	}
	return (NULL);
}
