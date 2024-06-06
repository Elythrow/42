/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hello <hello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:05 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/30 22:31:02 by hello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;

	i = 0;
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i ++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		join[i] = s2[i - ft_strlen(s1)];
		i ++;
	}
	join[i] = '\0';
	return (join);
}
