/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/29 14:28:20 by ysirkich         ###   ########.fr       */
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
	mlx_loop_hook(mlx->mlx, render_fractal, fractal); //gonna render fractal continuosly
	mlx_loop(mlx->mlx);//gonna handle events
	free(fractal);
	free(mlx);
	return (0);
}

void	key_callback() //process key events and close the window when the escape key is pressed.
{

}

int	error (char *text, t_fractol *fractal)
{
	ft_putstr_fd(text, 2);
	if (fractal)
		free(fractal);
	exit(EXIT_FAILURE);
}
