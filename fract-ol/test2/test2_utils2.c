/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:08:19 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:10:50 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

void	set_julia(t_fractal *fractal, char *real, char *imaginary, char *name)
{
	is_valid_julia(real, imaginary);
	fractal->vars.x_min = -1.5;
	fractal->vars.x_max = 1.5;
	fractal->vars.y_min = -1.5;
	fractal->vars.y_max = 1.5;
	fractal->c.r = ft_atod(real);
	fractal->c.i = ft_atod(imaginary);
	if (fractal->vars.x_min >= 0)
		fractal->vars.dist_x = fractal->vars.x_max - fractal->vars.x_min;
	else if (fractal->vars.x_max <= 0)
		fractal->vars.dist_x = fractal->vars.x_min - fractal->vars.x_max;
	else
		fractal->vars.dist_x = -fractal->vars.x_min + fractal->vars.x_max;
	if (fractal->vars.y_min >= 0)
		fractal->vars.dist_y = fractal->vars.y_max - fractal->vars.y_min;
	else if (fractal->vars.y_max <= 0)
		fractal->vars.dist_y = fractal->vars.y_min - fractal->vars.y_max;
	else
		fractal->vars.dist_y = -fractal->vars.y_min + fractal->vars.y_max;
	fractal->name = (char *)name;
	fractal->iter = 150;
	fractal->color_def = BLACK;
}

void	is_valid_julia(char *real, char *imaginary)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (real[i] == '-' || imaginary[i] == '+')
		i++;
	while (real[i])
	{
		if (!ft_isdigit(real[i]) && real[i] != '.')
			invalid_args();
		i++;
	}
	while (imaginary[j])
	{
		if (!ft_isdigit(imaginary[j]) && imaginary[j] != '.')
			invalid_args();
		j++;
	}
}

void	julia(double x, double y, t_fractal *fractal)
{
	int		i;
	double	z_x;
	double	z_y;
	double	temp_x;
	double	temp_y;

	z_x = x;
	z_y = y;
	i = 0;
	while (i < fractal->iter)
	{
		temp_x = ((z_x * z_x) - (z_y * z_y)) + fractal->c.r;
		temp_y = (2 * z_x * z_y) + fractal->c.i;
		if ((temp_x * temp_x) + (temp_y * temp_y) > 4)
		{
			fractal->color = (RED / fractal->iter) * i + fractal->color_def;
			return ;
		}
		z_x = temp_x;
		z_y = temp_y;
		i++;
	}
	fractal->color = BLACK;
}
