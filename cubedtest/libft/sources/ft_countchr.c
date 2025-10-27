/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:21:34 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/26 14:21:50 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchr(char *str, char c)
{
	int	count;
	int	i;

	if (!str)
		return (0);
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count ++;
	}
	return (count);
}
