/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:54:49 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/28 21:55:46 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	render_fractal(void *smthg) //generating and displaying fractals
{
	t_fractol	*fractal;
	t_mlx		*mlx;
	int			color;
	int			x;
	int			y;

	fractal = (t_fractal *)smthg;
	mlx = fractal->mlx;
	y = 0
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fractal->type == MANDELBROT)
				color = mandelbrot_pixel(fractal, x , y);
			else if (fractal->type == JULIA)
				color = julia_pixel(fractal, x, y);
			mlx_put_pixel(mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0); //image rendering to put it to the window
}

void	get_rgb(int iterations, int max_iterations)//defines a color based on the number of iterations.
{
	int	red;
	int	green;
	int	blue;

	if (iterations == fractal->max_iterations)
		return (BLACK);
	//colors based on the iteration count
	red = (iteration % 256);
	green = (iteration * 2) % 256;
	blue = (iterations * 2) % 256;
	return ((red << 16) | (green << 8) | blue);
}