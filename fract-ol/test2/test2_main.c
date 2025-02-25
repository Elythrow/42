/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:06:47 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:07:01 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

void	mlx_funcs(t_fractal *fractal)
{
	fractal->disp = mlx_init();
	if (fractal->disp == NULL)
		malloc_error("Error calling mlx_init\n", fractal);
	fractal->win = mlx_new_window(fractal->disp, WIDTH, HEIGHT, fractal->name);
	if (fractal->win == NULL)
		malloc_error("Error calling mlx_new_window\n", fractal);
	mlx_mouse_hook(fractal->win, mouse_events, fractal);
	mlx_key_hook(fractal->win, key_release, fractal);
	mlx_hook(fractal->win, KeyPress, KeyPressMask, key_press, fractal);
	mlx_hook(fractal->win, DestroyNotify, ButtonReleaseMask, quit, fractal);
	mlx_expose_hook(fractal->win, render, fractal);
	mlx_loop(fractal->disp);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_memset(&fractal, 0, sizeof(fractal));
	if ((argc == 4 && !ft_strncmp(argv[1], "julia", 5)) || (argc == 2
			&& (!ft_strncmp(argv[1], "mandelbrot", 10))) || (argc == 2
			&& (!ft_strncmp(argv[1], "fern", 4))))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			if (ft_countchr(argv[2], '.') > 1 || ft_countchr(argv[3], '.') > 1)
				invalid_args();
			set_julia(&fractal, argv[2], argv[3], argv[1]);
		}
		else if (!ft_strncmp(argv[1], "mandelbrot", 10))
			set_mandelbrot(&fractal, argv[1]);
		mlx_funcs(&fractal);
		cleanup(&fractal);
		return (0);
	}
	invalid_args();
}
