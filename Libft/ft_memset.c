/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:11:58 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/21 14:51:43 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;


	i = 0;
	if (s == NULL)
		return (NULL);
	str = s;
	while (s[i] && n > 0)
	{
		str[i] = (unsigned char)c;
		i ++;
		n --;
	}
	return (str);
}
