/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hello <hello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:05 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/29 12:41:58 by hello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*join;
	size_t	i;

	i = 0;
	join = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		join[i] = str1[i];
		i ++;
	}
	while (i < (ft_strlen(str1) + ft_strlen(str2)))
	{
		join[i] = str2[i - ft_strlen(str1)];
		i ++;
	}
	join[i] = '\0';
	return (join);
}
