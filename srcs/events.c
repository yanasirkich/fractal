/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:18:56 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/29 16:19:37 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_callback(mlx_key_data_t keydata, void *param) //close the window when the escape key is pressed.
{
	t_fractol	*fractal;

	fractal = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx->mlx);
}

void	close_callback(void *param)// close the window
{
	t_fractol	*fractal;

	fractal = (t_fractol *)param;
	mlx_close_window(fractal->mlx->mlx);
}

void	scroll_callback(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;

	fractal = (t_fractol *)param;
	//scroll up (zoom in) when ydelta > 0, scroll down (zoom out) when ydelta < 0
	if (ydelta > 0)
		fractal->zoom *= ZOOM_FACTOR;
	else if (ydelta < 0)
		fracta;->zoom /= ZOOM_FACTOR;
}