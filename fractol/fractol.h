/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:44:47 by sfrey             #+#    #+#             */
/*   Updated: 2021/06/18 20:05:06 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h"
# include <string.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		w_width;
	int		w_height;
}				t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		line_l;
	int		height;
	int		bpp;
	int		en;
}				t_img;

typedef struct s_all
{
	t_win			win;
	double			offset_x;
	double			offset_y;
	double			zoom;
	double			initial_x;
	double			initial_y;
	double			kr;
	double			kg;
	double			kb;
	unsigned int	max_depth;
	int				fract_type;
	t_img			display;
}				t_all;

int				krestik(void);
int				key_hook(int keycode, t_all *all);
int				mouse_press(int button, int x, int y, t_all *all);
void			clear_struct(t_all *all);
int				no_args_output(void);
void			set_fractal(t_all *all, int argc, char **argv);
void			calculate(t_all *all);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	jmyhocolor(unsigned int i, double kr, double kg, double kb);
unsigned int	burning_ship(t_all *all, double cy, \
double cx, unsigned int max);
unsigned int	mandelbrot(t_all *all, double cy, double cx, unsigned int max);
unsigned int	julia(t_all *all, double x, double y);

#endif
