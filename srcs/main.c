/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:30 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/13 13:15:19 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//iterates through the pixels of the window and calls the appropriate function to draw the fractal

int	main(int argc, char **argv)
{
	t_fractol	*fractal;

	if (argc < 2)
		error("Error. Not enough or too many arguments", NULL);//maybe make a specific message with all the fractal options etc in the future
	fractal = fractal_init(argv[1]); // function that checks fractals name
	if (!fractal)
		error("Error. Fractal's name is invalid.", fractal);
	init_fractal(fractal);
	init_mlx(fractal);
	//rendering logic
	free(fractal);
	return (0);
}

int	error (char *text, t_fractol *fractal)
{
	ft_putstr_fd(text, 2);
	if (fractal || *fractal)
	{
		free(fractal);
		*fractal = NULL;
	}
	exit(EXIT_FAILURE);
}
