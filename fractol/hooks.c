/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:31:00 by sfrey             #+#    #+#             */
/*   Updated: 2021/06/18 18:34:19 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	krestik(void)
{
	exit(0);
	return (0);
}

static void	switch_colors(t_all *all)
{
	if (all->kr == 0.11)
	{
		all->kr = 0.01;
		all->kg = 0.01;
		all->kb = 0.01;
	}
	else
	{
		all->kr = 0.11;
		all->kg = 0.19;
		all->kb = 0.3;
	}
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 126)
		all->offset_y += 0.1 * all->zoom;
	else if (keycode == 125)
		all->offset_y -= 0.1 * all->zoom;
	else if (keycode == 123)
		all->offset_x += 0.1 * all->zoom;
	else if (keycode == 124)
		all->offset_x -= 0.1 * all->zoom;
	else if (keycode == 48)
		switch_colors(all);
	else if (keycode == 24)
	{
		if (all->max_depth == 0)
			all->max_depth = 1;
		else
			all->max_depth *= 2;
	}
	else if (keycode == 27)
		all->max_depth /= 2;
	else if (keycode == 53)
		exit(0);
	calculate(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->display.img, 0, 0);
	return (0);
}

int	mouse_press(int button, int x, int y, t_all *all)
{
	if (x == -1 || y == -1)
	{
		printf("Congratulations! You just pointed your mouse cursor");
		printf("over the -1, -1 coordinates! I hope you're happy!\n");
	}
	if (button == 4)
		all->zoom *= 0.5;
	else if (button == 5)
		all->zoom *= 2;
	calculate(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->display.img, 0, 0);
	return (0);
}
