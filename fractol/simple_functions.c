/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:30:09 by sfrey             #+#    #+#             */
/*   Updated: 2021/06/18 19:23:41 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_atoi(const char *str)
{
	int	buf;
	int	neg;

	neg = 1;
	buf = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'\
		|| *str == '\v' || *str == '\f' || *str == '\n')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		buf = (buf * 10) + (*str - '0');
		str++;
	}
	return (buf * neg);
}

void	clear_struct(t_all *all)
{
	all->offset_x = 0;
	all->offset_y = 0;
	all->initial_x = -0.35;
	all->initial_y = 0.63;
	all->fract_type = 0;
	all->zoom = 1;
	all->max_depth = 128;
	all->kr = 0.11;
	all->kg = 0.19;
	all->kb = 0.3;
	all->win.mlx = mlx_init();
	all->win.w_height = 800;
	all->win.w_width = 800;
	all->win.win = mlx_new_window(all->win.mlx, \
	all->win.w_width, all->win.w_height, "fractol");
}

int	no_args_output(void)
{
	printf("List of possible arguments:\nM - Mandelbrot\nB - Burning ship\n");
	printf("J x y - Julia (default x = -0.35, y = 0.63)\n");
	return (0);
}

void	set_fractal(t_all *all, int argc, char **argv)
{
	if (argv[1][0] == 'M')
	{
		all->fract_type = 1;
		if (argc > 2)
			printf("Mandelbrot set doesn't need any additional parameters, \
they will be ignored\n");
	}
	else if (argv[1][0] == 'B')
	{
		all->fract_type = 3;
		if (argc > 2)
			printf("Burning ship doesn't need any additional parameters, \
they will be ignored\n");
	}
	else if (argv[1][0] == 'J')
	{
		all->fract_type = 2;
		if (argc > 2)
			all->initial_x = (double)ft_atoi(argv[2]) / 1000;
		if (argc == 4)
			all->initial_y = (double)ft_atoi(argv[3]) / 1000;
	}
}
