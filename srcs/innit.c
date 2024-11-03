/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/03 12:08:03 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractal_init(char *name)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	if (!fractal)
		error("fractal_init", "Error. Memory allocation failed.", NULL);
	fractal->mlx = malloc(sizeof(t_mlx));
    if (!fractal->mlx)
    {
        free(fractal);
        return NULL; // Handle allocation failure
    }
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
		fractal->type = 1;
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
	}
	else
	{
		free(fractal->mlx); // Free the mlx before returning
        free(fractal);
		error("fractal_init", "Error. smth\n", fractal);
	}
	return (fractal);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		error("init_mlx","Error. Memory allocation for MLX failed\n", NULL);
	mlx->mlx = mlx_init(HEIGHT, WIDTH, "Fractol Window", false);
	if(!mlx->mlx)
		error("init_mlx","Error. MLX initialization failed!\n", mlx); //maybe think of a function that would close mlx properly idk
	mlx->image = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);//maybe make it a separete function later on
	if (!mlx->image)
	{
		mlx_terminate(mlx->mlx);
		error("init_mlx","Error. Image creation failed!\n", mlx); 
	}
	return (mlx);
}