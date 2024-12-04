/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:58:00 by gbazin            #+#    #+#             */
/*   Updated: 2024/12/04 17:12:09 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
	{
		tmp = "(null)";
		while (tmp[i])
		{
			if (ft_print_c(tmp[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (ft_print_c(str[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}
