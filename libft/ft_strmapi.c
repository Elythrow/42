/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hello <hello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:53 by gbazin            #+#    #+#             */
/*   Updated: 2024/06/02 19:02:50 by hello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*mapi;
	size_t	i;

	i = 0;
	mapi = malloc(ft_strlen(str) + 1);
	if (mapi == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		mapi[i] = f(i, str[i]);
		i ++;
	}
	mapi[i] = '\0';
	return (mapi);
}
