/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:11:11 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:11:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

void	invalid_args(void)
{
	ft_putstr_fd("Invalid arguments\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("./fractol julia [real] [imaginary]\n", 2);
	ft_putstr_fd("./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol fern\n", 2);
	exit(1);
}

void	malloc_error(char *str, t_fractal *fractal)
{
	ft_putstr_fd(str, 2);
	cleanup(fractal);
	exit(1);
}

void	cleanup(t_fractal *fractal)
{
	if (fractal->disp)
	{
		if (fractal->img.img)
			mlx_destroy_image(fractal->disp, fractal->img.img);
		if (fractal->win)
			mlx_destroy_window(fractal->disp, fractal->win);
		mlx_destroy_display(fractal->disp);
		free(fractal->disp);
	}
}

int	quit(t_fractal *fractal)
{
	cleanup(fractal);
	exit(0);
}
