/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/08 02:37:46 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//iterates through the pixels of the window and calls the appropriate function to draw the fractal

int	main(int argc, char **argv)
{
	t_fractol	*fractal;

	if (argc != 2)
		error("main", "Error. Not enough or too many arguments\n", NULL);//make a specific message with all the fractal options etc in the future
	fractal = fractal_init(argv[1]);
	if (!fractal || !fractal->mlx || !fractal->mlx->image)
		error("main", "Error. Initialization failed\n", fractal);
	printf("Fractal pointer: %p\n", (void *)fractal);				//DEBUG
    printf("Fractal mlx pointer: %p\n", (void *)fractal->mlx);		//DEBUG
    printf("MLX image pointer: %p\n", (void *)fractal->mlx->image);	//DEBUG
	
	mlx_key_hook(fractal->mlx->mlx, key_callback, fractal); 
	mlx_close_hook(fractal->mlx->mlx, close_callback, fractal);
	mlx_scroll_hook(fractal->mlx->mlx, scroll_callback, fractal);
	mlx_resize_hook(fractal->mlx->mlx, resize_handler, fractal);
	mlx_loop_hook((mlx_t *)fractal->mlx->mlx, render_fractal, fractal);
	
	printf("Entering MLX loop...\n"); 	//DEBUG						//DEBUG
	
	mlx_loop(fractal->mlx->mlx);

	mlx_delete_image(fractal->mlx->mlx, fractal->mlx->image);
    mlx_terminate(fractal->mlx->mlx);
	free(fractal);
	free(fractal->mlx);
	return (0);
}

int	error (char *function, char *text, t_fractol *fractal)
{
	if (function)
		ft_putstr_fd(function, 2);
	if (text)
		ft_putstr_fd(text, 2);
	if (fractal)
	{
		if (fractal->mlx)
		{	if (fractal->mlx->mlx)
				mlx_terminate(fractal->mlx->mlx);
			if (fractal->mlx->image)
				mlx_delete_image(fractal->mlx->mlx, fractal->mlx->image);
			free(fractal->mlx);
		}
		free(fractal);
	}
	exit(EXIT_FAILURE);
}
