/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:21:56 by sfrey             #+#    #+#             */
/*   Updated: 2021/06/18 18:16:46 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(t_all *all, double cy, double cx, unsigned int max)
{
	double			x;
	double			y;
	double			x2;
	double			y2;
	unsigned int	i;

	i = 0;
	x2 = 0;
	y2 = 0;
	y = 0;
	x = 0;
	while (x2 + y2 <= 4 && i++ < max)
	{
		y = 2 * x * y + cy;
		x = x2 - y2 + cx;
		x2 = x * x;
		y2 = y * y;
	}
	if (i >= max)
		return (0);
	return (jmyhocolor(i, all->kr, all->kg, all->kb));
}

unsigned int	burning_ship(t_all *all, double cy, double cx, unsigned int max)
{
	double			x;
	double			y;
	double			x2;
	double			y2;
	unsigned int	i;

	i = 0;
	x2 = 0;
	y2 = 0;
	y = 0;
	x = 0;
	while (x2 + y2 <= 4 && i++ < max)
	{
		x = fabs(x);
		y = fabs(y);
		y = 2 * x * y + cy;
		x = x2 - y2 + cx;
		x2 = x * x;
		y2 = y * y;
	}
	if (i >= max)
		return (0);
	return (jmyhocolor(i, all->kr, all->kg, all->kb));
}

unsigned int	julia(t_all *all, double x, double y)
{
	double			cx;
	double			cy;
	double			x2;
	double			y2;
	unsigned int	i;

	i = 0;
	x2 = x * x;
	y2 = y * y;
	cy = all->initial_y;
	cx = all->initial_x;
	while (x2 + y2 <= 4 && i++ < all->max_depth)
	{
		y = 2 * x * y + cy;
		x = x2 - y2 + cx;
		x2 = x * x;
		y2 = y * y;
	}
	if (i >= all->max_depth)
		return (0);
	return (jmyhocolor(i, all->kr, all->kg, all->kb));
}
