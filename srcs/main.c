/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/22 11:39:30 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//iterates through the pixels of the window and calls the appropriate function to draw the fractal

int	main(int argc, char **argv)
{
	t_fractol	*fractal;
	t_mlx		*mlx;

	if (argc != 2)
		error("Error. Not enough or too many arguments\n", NULL);//maybe make a specific message with all the fractal options etc in the future
	fractal = fractal_init(argv[1]); // function that checks fractals name
	if (!fractal)
		error("Error. Fractal's name is invalid.\n", fractal);
	mlx = init_mlx();
	//render_fractal(fractal); or | ??
	mlx_loop_hook(mlx->mlx, render_fractal, fractal); //gonna render fractal continuosly
	mlx_key_hook(mlx->mlx, mlx_key_hook, fractal); 
	mlx_loop(mlx->mlx);//gonna handle events
	free(fractal);
	free(mlx);
	return (0);
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
int	error (char *text, t_fractol *fractal)
{
	ft_putstr_fd(text, 2);
	if (fractal)
		free(fractal);
	exit(EXIT_FAILURE);
}
