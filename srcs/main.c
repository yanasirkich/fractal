/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/29 16:35:05 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//iterates through the pixels of the window and calls the appropriate function to draw the fractal

int	main(int argc, char **argv)
{
	t_fractol	*fractal;
	t_mlx		*mlx;

	if (argc != 2)
		error("Error. Not enough or too many arguments\n", NULL);//make a specific message with all the fractal options etc in the future
	fractal = fractal_init(argv[1]);
	//if (!fractal)
	//	error("Error. Fractal's name is invalid.\n", fractal);
	mlx = init_mlx();
	mlx_key_hook(mlx->mlx, key_callback, fractal); 
	mlx_close_hook(mlx->mlx, close_callback, fractal);
	mlx_scroll_hook(mlx->mlx, scroll_callback, fractal);
	mlx_loop_hook(mlx->mlx, render_fractal, fractal); //gonna render fractal continuosly

	mlx_loop(mlx->mlx);//gonna handle events

	free(fractal);
	free(mlx);
	return (0);
}

int	error (char *text, void *data)
{
	ft_putstr_fd(text, 2);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}
