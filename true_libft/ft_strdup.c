/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:13 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 18:14:26 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	char			*dup;

	if (str == NULL)
		return (NULL);
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
