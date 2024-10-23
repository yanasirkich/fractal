/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:01:53 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/23 11:57:43 by ysirkich         ###   ########.fr       */
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
	fractal->max_iterations = 50;
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name, "mandelbrot") == 0)
		fractal->type = MANDELBROT;
	if (ft_strcmp(name, "Julia") == 0 || ft_strcmp(name, "julia") == 0)
	{
		fractal->type = JULIA;
		fractal->cx = -0.7; //constants for julia 
        fractal->cy = 0.27015;
	}
	else
		error("Error.\n", fractal);
	return (fractal);
}

int	*mandelbrot_pixel(t_fractol *fractal, int x, int y)// iterate over the mandelbrot equation and determine how quickly the point escapes
{ //z = z^2 + c z 
	double	real;
	double	imaginary;

	double	z_real;
	double	z_imaginary;

	double	z_sq_real;
	double	z_sq_imag;

	double	c_real;
	double	c_imaginary;
	
	int		iterations;

	real = (x - (WIDTH / 2)) / ((WIDTH / 4) * fractal->zoom) + fractal->offset_x;
	imaginary = (y - (HEIGHT / 2)) / ((HEIGHT / 4) * fractal->zoom) + fractal->offset_y;
	//initialize z to 0 + 0i
	z_real = 0.0;
	z_imaginary = 0.0;
	z_sq_real - 0.0;
	z_sq_imag = 0.0;
	iterations = 0;
	c_real = real;
	c_imaginary = imaginary;
	//z = z^2 + c iteration
	while (z_sq_real + z_sq_imag < 4 && fractal->max_iterations)
	{
		z_imaginary = 2 * z_real * z_imaginary + c_imaginary;
		z_real = z_sq_real - z_sq_imag + c_real;
		z_sq_real = z_real * z_real;
		z_sq_imag = z_imaginary * z_imaginary;
		iterations++;
	}
	if (iterations == fractal->max_iterations)
		return(BLACK);
	else
		return (GREEN * iterations / fractal->max_iterations);

}

//int	*julia_pixel(t_fractol *fractal, int x, int y)
//{
//	
//}

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
