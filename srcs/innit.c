/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/29 13:24:39 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractal_init(char *name)
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
	else if (ft_strcmp(name, "Julia") == 0 || ft_strcmp(name, "julia") == 0)
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

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		error("Error. Memory allocation for MLX failed\n", NULL);
	mlx->mlx = mlx_init(HEIGHT, WIDTH, "Fractol Window", false);
	if(!mlx->mlx)
		error("Error. MLX initialization failed!\n", mlx); //maybe think of a function that would close mlx properly idk
	mlx->image = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);//maybe make it a separete function later on
	if (!mlx->image)
		error("Error. Image creation failed!\n", mlx); 
	return (mlx);
}