/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:37 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 18:06:41 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

size_t	ft_countstart(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_charset(str[i], set) == 1)
		i ++;
	return (i);
}

size_t	ft_countend(char const *str, char const *set)
{
	size_t	i;

	i = ft_strlen(str);
	while ((i > 0) && ft_charset(str[i - 1], set) == 1)
		i --;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (set == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return (ft_calloc(1, 1));
	start = ft_countstart(s1, set);
	end = ft_countend(s1, set);
	trim = ft_substr(s1, start, end - start);
	return (trim);
}
