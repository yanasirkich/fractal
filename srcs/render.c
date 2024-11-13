/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:54:49 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/13 10:13:18 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(void *smthg) //generating and displaying fractals
{
	t_fractol	*fractal;
	t_mlx		*mlx;
	int			color;
	int			x;
	int			y;

	fractal = (t_fractol *)smthg;
	mlx = fractal->mlx;
	if (!fractal || !fractal->mlx || !fractal->mlx->image) 
    	error("render_fractal", "Error. fractal or fractal->mlx or mlx->image is NULL\n", fractal);
	fractal->aspect_ratio = (double)fractal->width / fractal->height;
	fractal->real_range = 2.0 * fractal->aspect_ratio / fractal->zoom;
	fractal->min_real = -fractal->real_range + fractal->offset_x;
	fractal->max_real = fractal->real_range + fractal->offset_x;
	fractal->min_imag = -2.0 / fractal->zoom + fractal->offset_y;
	fractal->max_imag = 2.0 / fractal->zoom + fractal->offset_y;
	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			if (fractal->type == 1)
				color = mandelbrot_pixel(fractal, x , y);
			else if (fractal->type == 2)
				color = julia_pixel(fractal, x, y);
			mlx_put_pixel(mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0); //image rendering to put it to the window
}

int	get_rgb(int iterations, t_fractol *fractal)//defines a color based on the number of iterations.
{
	int	red;
	int	green;
	int	blue;

	if (iterations == fractal->max_iterations)
		return (BLACK);
	//colors based on the iteration count
	red = (iterations % 256);
	green = (iterations * 2) % 256;
	blue = (iterations * 2) % 256;
	return ((red << 16) | (green << 8) | blue);
}