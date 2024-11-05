/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:18:56 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/05 19:18:50 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_callback(mlx_key_data_t keydata, void *param) //close the window when the escape key is pressed.
{
	t_fractol	*fractal;
	
	if (!param)
        error("key_callback", "Error. Key callback called with NULL param\n", NULL);
	fractal = (t_fractol *)param;
	if (!fractal->mlx || !fractal->mlx->mlx)
		error("key_callback", "Error. Fractal or MLX is not initialized properly\n", fractal);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_putstr_fd("Escape key pressed. Closing window...\n", 2);
		mlx_close_window(fractal->mlx->mlx);
	}
}

void	close_callback(void *param)
{
	t_fractol	*fractal;
	if (!param)
		error("close_callback", "Close callback called with NULL param\n", NULL);
	fractal = (t_fractol *)param;
	if (!fractal->mlx || !fractal->mlx->mlx)
		error("close_callback", "Error. Fractal or MLX is not initialized properly\n", fractal);
	ft_putstr_fd("Window close callback invoked. Closing window...\n", 2);
	mlx_close_window(fractal->mlx->mlx);
}

void	scroll_callback(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;
	if (!param) 
		error("scroll_callback", "Error. Scroll callback called with NULL param\n\n", NULL);
	fractal = (t_fractol *)param;
	if (!fractal->mlx || !fractal->mlx->mlx)
		error("scroll_callback", "Error. Fractal or MLX is not initialized properly\n", fractal);
	(void)xdelta; //unused parameter
	//scroll up (zoom in) when ydelta > 0, scroll down (zoom out) when ydelta < 0
	if (ydelta > 0)
		fractal->zoom *= ZOOM_FACTOR;
	else if (ydelta < 0)
		fractal->zoom /= ZOOM_FACTOR;
}

void	resize_handler(int new_width, int new_height, void	*param)
{
	t_fractol	*fractal;
	double		aspect_ratio;
	double		real_range;
	
	fractal = (t_fractol *)param;
	if (new_height != fractal->height || new_width != fractal->width)
	{
		fractal->height = new_height;
		fractal->width = new_width;
		aspect_ratio = (double)fractal->width / fractal->height;
		real_range = 2.0 * aspect_ratio;
		fractal->min_real = -real_range / fractal->zoom + fractal->offset_x;
		fractal->max_real = real_range / fractal->zoom + fractal->offset_x;
		fractal->min_imag = -2.0 / fractal->zoom + fractal->offset_y;
		fractal->max_imag = 2.0 / fractal->zoom + fractal->offset_y;
		mlx_delete_image(fractal->mlx->mlx, fractal->mlx->image);
		fractal->mlx->image = mlx_new_image(fractal->mlx->mlx, fractal->width, fractal->height);
		render_fractal(fractal);
	}
}
