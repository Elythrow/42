/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:15:35 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 19:48:35 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(&str[i]));
		i ++;
	}
	if (str[i] == (char)c)
		return ((char *)(&str[i]));
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*dup;

	i = 0;
	i = ft_strlen(str);
	dup = malloc(i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			len_s1;
	size_t			len_s2;
	char			*join;
	unsigned int	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (i < len_s1)
	{
		join[i] = s1[i];
		i ++;
	}
	while (i < (len_s1 + len_s2))
	{
		join[i] = s2[i - len_s1];
		i ++;
	}
	join[i] = '\0';
	return (join);
}
