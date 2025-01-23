/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:53 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/23 15:42:01 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	const size_t	output_len = ft_strlen(s);
	char			*output;

	i = 0;
	output = (char *)malloc(sizeof(char) * (output_len + 1));
	if (output == NULL)
	{
		return (NULL);
	}
	while (i < output_len)
	{
		if (f != NULL)
		{
			output[i] = f(i, s[i]);
		}
		++i;
	}
	output[i] = '\0';
	return (output);
}
