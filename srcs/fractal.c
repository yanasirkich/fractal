/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:01:53 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/13 13:37:26 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	fractal_init(char *name)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	if (!fractal)
		error("Error. Memory allocation failed.", NULL);
	if (ft_strcmp(name, "Mandelbrot") == 0)
		mandelbrot_init(fractal);
	if (ft_strcmp(name, "Julia") == 0)
		julia_init(fractal);
	else
	{
		ft_putendl_fd("Error. Wrong input. Usage: ./fractol [julia] or [mandelbrot]", 1);
		return (NULL);
	}
	return (0);
}

void	*mandelbrot_init()