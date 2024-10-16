/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/16 15:29:22 by ysirkich         ###   ########.fr       */
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
	init_mlx(mlx);
	init_fractal(fractal);
	//rendering logic
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
	mlx->mlx = mlx_init(800, 600, "Fractol Window", false);
	if(!mlx->mlx)
		error("Error. MLX42 initialization failed!\n", NULL);
	mlx_key_hook(mlx, key_hook, mlx); // to do
	mlx_loop(mlx); // to do
	mlx_terminate(mlx);
}
int	error (char *text, t_fractol *fractal)
{
	ft_putstr_fd(text, 2);
	if (fractal)
		free(fractal);
	exit(EXIT_FAILURE);
}
