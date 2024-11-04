/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/04 04:05:39 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractal_init(char *name)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	if (!fractal)
		error("fractal_init", "Error. Memory allocation failed.", NULL);
	//fractal->mlx = malloc(sizeof(t_mlx));
	fractal->mlx = init_mlx();
    if (!fractal->mlx)
    {
		free(fractal);  
		error("fractal_init", "Memory allocation failed for MLX.", NULL);
	}
	printf("MLX struct allocated within fractal.\n"); // DEBUG
    fractal->zoom = 1.0;	//a separete function at some pont
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
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name, "mandelbrot") == 0)
	{
		fractal->min_real = -2.0;
        fractal->max_real = 1.0;
        fractal->min_imag = -1.5;
        fractal->max_imag = 1.5;
		fractal->type = 1;
		printf("Mandelbrot parameters set.\n"); //DEBUG
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
		printf("JUlia parameters set.\n");  //DEBUG
	}
	else
	{
		free(fractal->mlx); // Free the mlx before returning
        free(fractal);
		error("fractal_init", "Error. Invalid fractal name provided.\n\n", NULL);
	}
	return (fractal);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		error("init_mlx","Error. Memory allocation for MLX failed\n", NULL);
	printf("Allocated MLX struct.\n"); //DEBUG
	mlx->mlx = mlx_init(HEIGHT, WIDTH, "Fractol Window", false);
	if(!mlx->mlx)
	{
		fprintf(stderr, "Error initializing MLX42 instance.\n");
		free(mlx);
		return NULL;
		//error("init_mlx","Error. MLX initialization failed!\n", mlx); //maybe think of a function that would close mlx properly idk
	}
	printf("MLX initialized successfully.\n");
	mlx->image = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);//maybe make it a separete function later on
	if (!mlx || !mlx->image)
	{
		fprintf(stderr, "Error initializing MLX42 instance.\n");		mlx_terminate(mlx->mlx);
		free(mlx);
		return NULL;
		//error("init_mlx","Error. Image creation failed!\n", mlx); 
	}
	printf("Image created successfully.\n"); //DEBUG
	return (mlx);
}