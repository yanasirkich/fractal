/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:00:12 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/22 12:12:32 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define	FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "MLX42/MLX42.h"

# define WIDTH 1280
# define HEIGHT 720

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