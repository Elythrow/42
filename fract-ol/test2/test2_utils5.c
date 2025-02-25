/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:11:33 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:11:41 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

void	zoom(t_fractal *fractal, int opt)
{
	if (opt == ZOOM_IN)
	{
		zoom_in_x(fractal);
		zoom_in_y(fractal);
	}
	else if (opt == ZOOM_OUT)
	{
		zoom_out_x(fractal);
		zoom_out_y(fractal);
	}
}

void	zoom_out_x(t_fractal *fractal)
{
	double	zoom_factor;

	zoom_factor = 1.0 / 5.0;
	if (fractal->vars.x_min >= 0)
	{
		fractal->vars.x_min += fractal->vars.dist_x * zoom_factor;
		fractal->vars.x_max -= fractal->vars.dist_x * zoom_factor;
	}
	else if (fractal->vars.x_max <= 0)
	{
		fractal->vars.x_min += fractal->vars.dist_x * zoom_factor;
		fractal->vars.x_max -= fractal->vars.dist_x * zoom_factor;
	}
	else
	{
		fractal->vars.x_min += fractal->vars.dist_x * zoom_factor;
		fractal->vars.x_max -= fractal->vars.dist_x * zoom_factor;
	}
	fractal->vars.dist_x = fabs(fractal->vars.x_max - fractal->vars.x_min);
}

void	zoom_out_y(t_fractal *fractal)
{
	double	zoom_factor;

	zoom_factor = 1.0 / 5.0;
	fractal->vars.y_min += fractal->vars.dist_y * zoom_factor;
	fractal->vars.y_max -= fractal->vars.dist_y * zoom_factor;
	fractal->vars.dist_y = fabs(fractal->vars.y_max - fractal->vars.y_min);
}

void	zoom_in_x(t_fractal *fractal)
{
	double	zoom_factor;

	zoom_factor = 1.0 / 5.0;
	if (fractal->vars.x_min >= 0)
	{
		fractal->vars.x_min -= fractal->vars.dist_x * zoom_factor;
		fractal->vars.x_max += fractal->vars.dist_x * zoom_factor;
	}
	else if (fractal->vars.x_max <= 0)
	{
		fractal->vars.x_min -= fractal->vars.dist_x * zoom_factor;
		fractal->vars.x_max += fractal->vars.dist_x * zoom_factor;
	}
	else
	{
		fractal->vars.x_min -= fractal->vars.dist_x * zoom_factor;
		fractal->vars.x_max += fractal->vars.dist_x * zoom_factor;
	}
	fractal->vars.dist_x = fabs(fractal->vars.x_max - fractal->vars.x_min);
}

void	zoom_in_y(t_fractal *fractal)
{
	double	zoom_factor;

	zoom_factor = 1.0 / 5.0;
	fractal->vars.y_min -= fractal->vars.dist_y * zoom_factor;
	fractal->vars.y_max += fractal->vars.dist_y * zoom_factor;
	fractal->vars.dist_y = fabs(fractal->vars.y_max - fractal->vars.y_min);
}
