/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/03 13:15:09 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//iterates through the pixels of the window and calls the appropriate function to draw the fractal

int	main(int argc, char **argv)
{
	t_fractol	*fractal;
	t_mlx		*mlx;

	if (argc != 2)
		error("main", "Error. Not enough or too many arguments\n", NULL);//make a specific message with all the fractal options etc in the future
	fractal = fractal_init(argv[1]);
	if (!fractal)
		error("main","Error. Fractal's name is invalid.\n", fractal);
	mlx = init_mlx();
	if (!mlx || !mlx->image) 
		error("main","Error: MLX initialization failed!\n", mlx);
	printf("Fractal pointer: %p\n", (void *)fractal); //DEBUG
    printf("Fractal mlx pointer: %p\n", (void *)fractal->mlx);//DEBUG
    printf("MLX image pointer: %p\n", (void *)mlx->image); //DEBUG
	mlx_key_hook(mlx->mlx, key_callback, fractal); 
	mlx_close_hook(mlx->mlx, close_callback, fractal);
	mlx_scroll_hook(mlx->mlx, scroll_callback, fractal);
	if (fractal && fractal->mlx && mlx->image) 
	{
		printf("Fractal: %p, MLX: %p, Image: %p\n", (void *)fractal, (void *)fractal->mlx, (void *)mlx->image); // DEBUG
		mlx_loop_hook((mlx_t *)fractal->mlx, render_fractal, fractal);
	}
 	else 
		error("main","Error: Fractal, MLX, or image initialization failed\n", fractal);
	printf("Entering MLX loop...\n"); //DEBUG
	
	mlx_loop(mlx->mlx);//gonna handle events

	mlx_delete_image(mlx->mlx, mlx->image);
    mlx_terminate(mlx->mlx);
	free(fractal);
	free(mlx);
	return (0);
}

int	error (const char *function, char *text, void *data)
{
	if (function)
		fprintf(stderr, "Error in %s: ", function);
	if (text)
		ft_putstr_fd(text, 2);
	if (data)
	{
		free(data);
		data = NULL;
	}
	exit(EXIT_FAILURE);
}
