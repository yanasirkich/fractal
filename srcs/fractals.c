/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:01:53 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/05 09:08:01 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_pixel(t_fractol *fractal, int x, int y)// iterate over the mandelbrot equation and determine how quickly the point escapes
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
		if (real * real + imaginary * imaginary > 4)
			break ;
		temp_real = real * real - imaginary * imaginary + c_real;
		imaginary = 2.0 * real * imaginary + c_imaginary;
		real = temp_real;
		iterations++;
	}
	return (get_rgb(iterations, fractal));
}

// z = z^2 + c for julia
int	julia_pixel(t_fractol *fractal, int x, int y)//ill try rbg lets see lol
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
	return (get_rgb(iterations, fractal));
}