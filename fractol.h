/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:12 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/23 11:58:02 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define	FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "MLX42/MLX42.h"

# define WIDTH 1280
# define HEIGHT 720

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED   0xFF0000
#define GREEN 0x00FF00
#define BLUE  0x0000FF
#define YELLOW 0xFFFF00
#define CYAN   0x00FFFF
#define MAGENTA 0xFF00FF

typedef struct s_fractol
{
	int		type;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		max_iterations;
	t_mlx	*mlx;
}	t_fractol;

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	///smtng else
}	t_mlx;