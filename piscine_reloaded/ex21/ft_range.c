/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:16 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/15 12:32:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	diff;
	int	i;
	int	*range;

	i = 0;
	diff = max - min;
	if (diff <= 0)
		return (NULL);
	range = malloc(sizeof(int) * diff);
	if (range == NULL)
		return (NULL);
	while (i < diff)
	{
		range[i] = min + i;
		i ++;
	}
	return (range);
}
