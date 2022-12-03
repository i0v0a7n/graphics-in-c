/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_and_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:24:30 by sfrey             #+#    #+#             */
/*   Updated: 2021/06/18 18:34:51 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	jmyhocolor(unsigned int i, double kr, double kg, double kb)
{
	int	r;
	int	g;
	int	b;

	r = sin(kr * i) * 256;
	g = sin(kg * i) * 256;
	b = sin(kb * i) * 256;
	return (((r << 16) & 0x00ff0000) | \
			((g << 8) & 0x0000ff00) | \
			(b & 0x000000ff));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static unsigned int	make_color(t_all *all, double y, double x)
{
	if (all->fract_type == 1)
		return (mandelbrot(all, \
		(y - 2) * all->zoom + all->offset_y, \
		(x - 2) * all->zoom + all->offset_x, \
		all->max_depth));
	if (all->fract_type == 3)
		return (burning_ship(all, \
		(y - 2) * all->zoom + all->offset_y, \
		(x - 2) * all->zoom + all->offset_x, \
		all->max_depth));
	else if (all->fract_type == 2)
		return (julia(all, \
		(y - 2) * all->zoom + all->offset_y, \
		(x - 2) * all->zoom + all->offset_x));
	else
	{
		printf("Fractal isn't set, that wasn't supposed to happen\n");
		exit (1);
		return (0);
	}
}

void	calculate(t_all *all)
{
	int				i;
	int				j;
	unsigned int	color;

	i = -1;
	while (++i < all->display.height)
	{
		j = -1;
		while (++j < all->display.line_l / 4)
		{
			color = make_color(all, \
			(double)(i * 4) / all->display.height, \
			(double)(j * 16) / all->display.line_l);
			my_mlx_pixel_put(&all->display, j, i, color);
		}
	}
}
