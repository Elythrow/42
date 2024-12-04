/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:54:42 by gbazin            #+#    #+#             */
/*   Updated: 2024/12/04 17:12:22 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *input_str, ...);
int		check_format(const char *str, va_list par, int i);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nb);
int		ft_put_ptr(unsigned long nbr);
int		ft_put_hex(unsigned int nbr, char *chars);
int		ft_print_c(char c);
int		ft_print_s(char *str);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_p(unsigned long ptr);
int		ft_print_x(unsigned int nbr, int format);

#endif