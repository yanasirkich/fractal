/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:12 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/08 02:38:02 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
# define	FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //delete later bc of norm

# include "./lib/MLX42/include/MLX42/MLX42.h"
# include "./lib/libft/libft.h"

# define WIDTH 1500
# define HEIGHT 720

# define BLACK 0x000000

# define ZOOM_FACTOR 1.1 //10% zoom maybe do 1.05 in the future

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define MOVE_STEP 0.1 // dont forget to adjust after checking out


//mlx instance is stored inside the fractal struct
typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
}	t_mlx;

typedef struct s_fractol
{
	int			type;
	double		zoom;
	int			height;
	int			width;
	double		offset_x;
	double		offset_y;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	int			max_iterations;
	double		cx; //for julia
	double		cy; //for julia
	t_mlx		*mlx; //pointer to mlx
}	t_fractol;

//other
int	error (char *function, char *text, t_fractol *fractal);
//innits
t_fractol	*fractal_init(char *name);
//rendering
void	render_fractal(void *smthg);
int	get_rgb(int iterations, t_fractol *fractal);
//fractals
int	mandelbrot_pixel(t_fractol *fractal, int x, int y);
int	julia_pixel(t_fractol *fractal, int x, int y);
//events
void	key_callback(mlx_key_data_t keydata, void *param);
void	close_callback(void *param);
void	scroll_callback(double xdelta, double ydelta, void *param);
void	resize_handler(int new_width, int new_height, void	*param);

#endif