/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:01:53 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/17 20:12:07 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	fractal_init(char *name)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	fractal->zoom = 1.0;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iterations = 50;
	if (!fractal)
		error("Error. Memory allocation failed.", NULL);
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name, "mandelbrot") == 0)
	{
		mandelbrot_init(fractal);
		fractal->name = "Mandelbrot"
	}
		mandelbrot_init(fractal);
	if (ft_strcmp(name, "Julia") == 0 || ft_strcmp(name, "julia") == 0)
	{
		julia_init(fractal);
		fractal->name = "Julia";
	}
	else
		error("Error.\n", fractal);
	return (fractal);
}

//void	*mandelbrot_init() to implement later
//void	*julia_init()

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
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			color = color_calculate(fractal, x , y); //pixel calculations
			//personal implementation pixel drawing function
			//or
			mlx_put_pixel(mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0); //image rendering to put it to the window
}