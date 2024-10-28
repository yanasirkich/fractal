/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:12 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/28 22:30:31 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define	FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1280
# define HEIGHT 720

#define BLACK 0x000000

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	///smtng else
}	t_mlx;

typedef struct s_fractol
{
	int			type;
	double		zoom;
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
int	error (char *text, t_fractol *fractal);
//innits
t_fractol	fractal_init(char *name);
t_mlx	*init_mlx(void);
//rendering
void	render_fractal(void *smthg);
void	get_rgb(int iterations, int max_iterations);
//fractals
int	*mandelbrot_pixel(t_fractol *fractal, int x, int y);
int	*julia_pixel(t_fractol *fractal, int x, int y);

#endif