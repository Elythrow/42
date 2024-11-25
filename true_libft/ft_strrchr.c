/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:44 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 19:57:08 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		size;

	size = ft_strlen(str) - 1;
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return ((char *)&str[size]);
		size --;
	}
	if (str[ft_strlen(str)] == (char)c)
		return ((char *)&str[ft_strlen(str)]);
	return (NULL);
}
