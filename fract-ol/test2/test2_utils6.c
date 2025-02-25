/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:09:02 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:12:08 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

int	mouse_events(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(fractal, ZOOM_IN);
	else if (button == 5)
		zoom(fractal, ZOOM_OUT);
	else
		return (0);
	mlx_destroy_image(fractal->disp, fractal->img.img);
	render(fractal);
	return (0);
}

int	key_release(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		quit(fractal);
	return (0);
}

int	key_press(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Down
		|| keysym == XK_Up)
		move(keysym, fractal);
	else if (keysym == XK_r)
		fractal->color_def += RED;
	else if (keysym == XK_g)
		fractal->color_def += GREEN;
	else if (keysym == XK_b)
		fractal->color_def += BLUE;
	else if (keysym == XK_i)
		fractal->iter += 25;
	else
		return (0);
	mlx_destroy_image(fractal->disp, fractal->img.img);
	render(fractal);
	return (0);
}

void	move(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Right)
	{
		fractal->vars.x_min += fractal->vars.dist_x / 5;
		fractal->vars.x_max += fractal->vars.dist_x / 5;
	}
	else if (keysym == XK_Left)
	{
		fractal->vars.x_min -= fractal->vars.dist_x / 5;
		fractal->vars.x_max -= fractal->vars.dist_x / 5;
	}
	else if (keysym == XK_Up)
	{
		fractal->vars.y_max -= fractal->vars.dist_y / 5;
		fractal->vars.y_min -= fractal->vars.dist_y / 5;
	}
	else if (keysym == XK_Down)
	{
		fractal->vars.y_max += fractal->vars.dist_y / 5;
		fractal->vars.y_min += fractal->vars.dist_y / 5;
	}
}
