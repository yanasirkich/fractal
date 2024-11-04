/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/04 20:32:35 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void fractal_defaults_init(t_fractol *fractal);

t_fractol	*fractal_init(char *name)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	if (!fractal)
		error("fractal_init", "Error. Memory allocation failed.", NULL);
	fractal->mlx = init_mlx(fractal);
    if (!fractal->mlx)
		error("fractal_init", "Memory allocation failed for MLX.", fractal);
	printf("MLX struct allocated within fractal.\n"); // DEBUG
	fractal_defaults_init(fractal);
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name, "mandelbrot") == 0)
	{
		fractal->min_real = -2.0;
        fractal->max_real = 1.0;
        fractal->min_imag = -1.5;
        fractal->max_imag = 1.5;
		fractal->type = 1;
		printf("Mandelbrot parameters set.\n"); 	//DEBUG
	}
	else if (ft_strcmp(name, "Julia") == 0 || ft_strcmp(name, "julia") == 0)
	{
		fractal->min_real = -2.0;
        fractal->max_real = 2.0;
        fractal->min_imag = -2.0;
        fractal->max_imag = 2.0;
		fractal->cx = -0.7; //constants for julia 
		fractal->cy = 0.27015;
		fractal->type = 2;
		printf("JUlia parameters set.\n");  		//DEBUG
	}
	else
		error("fractal_init", "Error. Invalid fractal name provided.\n", fractal);
	return (fractal);
}

t_mlx	*init_mlx(t_fractol *fractal)
{
	fractal->mlx = malloc(sizeof(t_mlx));
	if (!fractal->mlx)
		error("init_mlx","Error. Memory allocation for MLX failed\n", fractal);
	printf("Allocated MLX struct.\n"); //DEBUG
	fractal->mlx->mlx = mlx_init(HEIGHT, WIDTH, "Fractol Window", false);
	if(!fractal->mlx->mlx)
		error("init_mlx", "Error initializing MLX42 instance.\n", fractal);
	printf("MLX initialized successfully.\n");				//DEBUG
	fractal->mlx->image = mlx_new_image(fractal->mlx->mlx, HEIGHT, WIDTH);
	if (!fractal->mlx->image)
		error("init_mlx","Error. Image creation failed!\n", fractal); 
	printf("Image created successfully.\n"); 				//DEBUG
	return (fractal->mlx);
}

static void fractal_defaults_init(t_fractol *fractal)
{
	fractal->zoom = 1.0;
    fractal->offset_x = 0;
    fractal->offset_y = 0;
    fractal->max_iterations = 100;
    fractal->min_real = 0.0;
    fractal->max_real = 0.0; 
    fractal->min_imag = 0.0; 
    fractal->max_imag = 0.0; 
    fractal->cx = 0.0; 
    fractal->cy = 0.0; 
    fractal->type = 0;
}