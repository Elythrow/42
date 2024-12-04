/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:53:43 by gbazin            #+#    #+#             */
/*   Updated: 2024/12/04 17:12:16 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *str, va_list par, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_c((char) va_arg(par, int));
	else if (str[i] == 's')
		count += ft_print_s((char *) va_arg(par, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_d((int) va_arg(par, int));
	else if (str[i] == 'u')
		count += ft_print_u((unsigned int) va_arg(par, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_print_x((unsigned int) va_arg(par, unsigned int), str[i]);
	else if (str[i] == 'p')
		count += ft_print_p((unsigned long) va_arg(par, unsigned long));
	else if (str[i] == '%')
		count += ft_print_c('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		i;
	int		count;

	va_start(params, str);
	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_format(str, params, ++i);
			if (count < 0)
				return (-1);
		}
		else
			count += ft_print_c(str[i]);
		i++;
	}
	va_end(params);
	return (count);
}
