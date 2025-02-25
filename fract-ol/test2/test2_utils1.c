/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:08:10 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:09:25 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

void	set_mandelbrot(t_fractal *fractal, char *name)
{
	fractal->vars.x_min = -2;
	fractal->vars.x_max = 1;
	fractal->vars.y_min = -1.5;
	fractal->vars.y_max = 1.5;
	fractal->vars.dist_x = fabs(fractal->vars.x_max - fractal->vars.x_min);
	fractal->vars.dist_y = fabs(fractal->vars.y_max - fractal->vars.y_min);
	fractal->name = name;
	fractal->iter = 150;
	fractal->color_def = BLACK;
}

void	mandelbrot(double x, double y, t_fractal *fractal)
{
	int		i;
	double	z_x;
	double	z_y;
	double	temp_x;
	double	temp_y;

	z_x = 0;
	z_y = 0;
	i = 0;
	while (i < fractal->iter)
	{
		temp_x = (z_x * z_x - z_y * z_y) + x;
		temp_y = (2 * z_x * z_y) + y;
		if (temp_x * temp_x + temp_y * temp_y > 4)
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
