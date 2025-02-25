/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:07:13 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/25 14:13:47 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST2_H
# define TEST2_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_var
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	dist_x;
	double	dist_y;
}	t_var;

typedef struct s_fractal
{
	char		*name;
	void		*disp;
	void		*win;
	t_img		img;
	int			color;
	int			color_def;
	t_complex	c;
	t_var		vars;
	int			iter;
}	t_fractal;

# define WIDTH 1200
# define HEIGHT 1000

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define ZOOM_IN 2
# define ZOOM_OUT 1

void    set_julia(t_fractal *fractal, char *real, char *imaginary, char *name);
void    is_valid_julia(char *real, char *imaginary);
void 	julia(double x, double y, t_fractal *fractal);

void 	mandelbrot(double x, double y, t_fractal *fractal);
void 	set_mandelbrot(t_fractal *fractal, char *name);

void	invalid_args(void);
void    cleanup(t_fractal *fractal);
int     render(t_fractal *fractal);
void	malloc_error(char *str, t_fractal *fractal);
int	    quit(t_fractal *fractal);

void    mlx_funcs(t_fractal *fractal);
void    move(int keysym, t_fractal *fractal);
int     key_press(int keysym, t_fractal *fractal);
int     key_release(int keysym, t_fractal *fractal);
void    zoom_in_follow(t_fractal *fractal, int x, int y);
int     mouse_events(int button, int x, int y, t_fractal *fractal);

void    zoom(t_fractal *fractal, int opt);
void    zoom_out_x(t_fractal *fractal);
void    zoom_out_y(t_fractal *fractal);
void    zoom_in_x(t_fractal *fractal);
void    zoom_in_y(t_fractal *fractal);

int render_pixel(t_fractal *fractal, int x, int y);

#endif