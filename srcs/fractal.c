/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:01:53 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/25 14:52:40 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	fractal_init(char *name)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	if (!fractal)
		error("Error. Memory allocation failed.", NULL);
	fractal->zoom = 1.0;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iterations = 100;
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name, "mandelbrot") == 0)
	{
		fractal->min_real = -2.0;
        fractal->max_real = 1.0;
        fractal->min_imag = -1.5;
        fractal->max_imag = 1.5;
		fractal->type = MANDELBROT;
	}
	if (ft_strcmp(name, "Julia") == 0 || ft_strcmp(name, "julia") == 0)
	{
		fractal->min_real = -2.0;
        fractal->max_real = 2.0;
        fractal->min_imag = -2.0;
        fractal->max_imag = 2.0;
		fractal->cx = -0.7; //constants for julia 
		fractal->cy = 0.27015;
		fractal->type = JULIA;
	}
	else
		error("Error. smth\n", fractal);
	return (fractal);
}

int	*mandelbrot_pixel(t_fractol *fractal, int x, int y)// iterate over the mandelbrot equation and determine how quickly the point escapes
{ //z = z^2 + c z 
	double	real;
	double	imaginary;
	double	c_real;
	double	c_imaginary;
	double	temp_real;
	int		iterations;
	real = 0;
	imaginary = 0;
	c_real = fractal->min_real + (x / (double)WIDTH) * (fractal->max_real - fractal->min_real);
	c_imaginary = fractal->min_imag + (y / (double)HEIGHT) * (fractal->max_imag - fractal->min_imag);
	iterations = 0;
	while (iterations < fractal->max_iterations)
	{
		if (real * real + imaginary + imaginary > 4)
			break ;
		temp_real = real * real - imaginary * imaginary + c_real;
		imaginary = 2.0 * real * imaginary + c_imaginary;
		real = temp_real;
		iterations++;
	}
}

// z = z^2 + c for julia
int	*julia_pixel(t_fractol *fractal, int x, int y)//ill try rbg lets see lol
{
	double	real;
	double	imaginary;
	double	temp_real;
	int		iterations;

	real = fractal->min_real + (x / (double)WIDTH) * (fractal->max_real - fractal->min_real);
	imaginary = fractal->min_imag + (y / (double)HEIGHT) * (fractal->max_imag - fractal->min_imag);
	iterations = 0;
	while (iterations < fractal->max_iterations)
	{
		//escape condition(real^2 + imaginary^2 > 4)
		if (real * real + imaginary * imaginary > 4)
			break ;
		//z^2real = real^2 - imaginary^2 || z^2imag = 2xrealximag
		temp_real = real * real - imaginary * imaginary + fractal->cx;
		imaginary = 2.0 * real * imaginary + fractal->cy;
		real = temp_real;
		iterations++;
	}
	if (iterations == fractal->max_iterations)
		return (BLACK); //points inside the set
	else
		return (get_rgb(iterations, fractal->max_iterations));
}

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
