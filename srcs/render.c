/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:54:49 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/05 19:11:57 by ysirkich         ###   ########.fr       */
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