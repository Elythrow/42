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

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	*str;

	str = (char *)s;
	size = ft_strlen(s);
	while (size >= 0)
	{
		if (str[size] == c)
			return (&str[size]);
		size --;
	}
	return (0);
}
