/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:30 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 18:27:33 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len_s - start < len)
		len = len_s - start;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		start ++;
		i ++;
	}
	sub[i] = '\0';
	return (sub);
}
