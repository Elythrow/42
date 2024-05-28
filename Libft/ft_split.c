/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:20 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/28 17:48:19 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i ++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 0 && word == 0)
		{
			word = 1;
			count ++;
		}
		if (is_sep(str[i], charset) == 1)
			word = 0;
		i ++;
	}
	return (count);
}

char	**ft_splitter(char *str, char *charset, char **array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[k])
	{
		j = 0;
		while (is_sep(str[k], charset) == 1)
			k ++;
		while (!is_sep(str[k], charset) && str[k])
		{
			array[i][j] = str[k];
			k ++;
			j ++;
		}
		array[i][j] = '\0';
		i ++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (ft_strlen(str) == 0)
	{
		array = malloc(sizeof(char *));
		array[0] = 0;
		return (array);
	}
	count = count_words(str, &c) + 1;
	array = malloc(sizeof(char *) * count);
	if (!array)
		return (NULL);
	while (i < count - 1)
	{
		array[i] = malloc((ft_strlen(str) + 1) * sizeof(char));
		if (!array[i])
			return (NULL);
		i ++;
	}
	return (ft_splitter(str, &c, array));
}
