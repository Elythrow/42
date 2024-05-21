/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:24:17 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/21 17:26:07 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, unsigned int n)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (r == 0)
	{
		if (i < n)
		{
			if (first[i] > second[i])
				r = 1;
			else if (first[i] < second[i])
				r = -1;
			else if (first[i] == '\0')
				break ;
			i++;
		}
		else
			break ;
	}
	return (r);
}