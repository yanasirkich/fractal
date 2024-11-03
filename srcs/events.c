/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:18:56 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/03 13:09:53 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_callback(mlx_key_data_t keydata, void *param) //close the window when the escape key is pressed.
{
	t_fractol	*fractal;
	
	if (!param)
        fprintf(stderr, "Key callback called with NULL param\n");
        return ;
	fractal = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("Escape key pressed. Closing window...\n"); // DEBUG
		mlx_close_window(fractal->mlx->mlx);
	}
}

void	close_callback(void *param)// close the window
{
	t_fractol	*fractal;
	if (!param)
	{
        fprintf(stderr, "Close callback called with NULL param\n");
        return;
	}
	fractal = (t_fractol *)param;
	printf("Window close callback invoked.\n");
	mlx_close_window(fractal->mlx->mlx);
}

void	scroll_callback(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;
	if (!param) {
    	fprintf(stderr, "Scroll callback called with NULL param\n");
        return; // Prevent dereferencing a NULL pointer
    }
	fractal = (t_fractol *)param;
	(void)xdelta; //unused parameter
	//scroll up (zoom in) when ydelta > 0, scroll down (zoom out) when ydelta < 0
	if (ydelta > 0)
		fractal->zoom *= ZOOM_FACTOR;
	else if (ydelta < 0)
		fractal->zoom /= ZOOM_FACTOR;
}