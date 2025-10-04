/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:20 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/23 15:25:37 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i ++;
		if (str[i] && str[i] != c)
			count ++;
		while (str[i] && str[i] != c)
			i ++;
	}
	return (count);
}

static char	*ft_ncopy(const char *str, size_t i, size_t j)
{
	char	*dest;

	dest = malloc((j - i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, &str[i], (j - i + 1));
	dest[j - i] = '\0';
	return (dest);
}

static char	**ft_splitter(char **array, const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i ++;
		j = i;
		while (str[j] && str[j] != c)
			j ++;
		if (i != j)
		{
			array[n] = ft_ncopy(str, i, j);
			if (!array[n])
				return (ft_free(array), NULL);
			n ++;
		}
		i = j;
	}
	array[n] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (ft_splitter(array, s, c));
}
