/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundamental.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:06:34 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 16:23:31 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render_next_frame(t_all *all)
{
	movements(all);
	ft_nullify(all->display, all->c_floor, all->c_ceiling);
	ft_put_opacity_square(all);
	ft_cast_ray(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->display.img, 0, 0);
	if (all->mapon == 1)
	{
		mlx_put_image_to_window(all->win.mlx,
			all->win.win, all->minimap.img, 0, 0);
		mlx_put_image_to_window(all->win.mlx,
			all->win.win, all->maprays.img, 0, 0);
	}
	if (all->mapon == 0)
		exit(0);
	return (0);
}

int	openboi(int keycode, t_all *all)
{
	if (keycode == 46)
		all->mapon *= -1;
	if (keycode == 123)
		all->inputs.leftturn = 1;
	if (keycode == 124)
		all->inputs.rightturn = 1;
	if (keycode == 1)
		all->inputs.movebackward = 1;
	if (keycode == 13)
		all->inputs.moveforward = 1;
	if (keycode == 0)
		all->inputs.moveleft = 1;
	if (keycode == 2)
		all->inputs.moveright = 1;
	if (keycode == 53)
		all->mapon = 0;
	return (0);
}

int	closeboi(int keycode, t_all *all)
{
	if (keycode == 123)
		all->inputs.leftturn = 0;
	if (keycode == 124)
		all->inputs.rightturn = 0;
	if (keycode == 1)
		all->inputs.movebackward = 0;
	if (keycode == 13)
		all->inputs.moveforward = 0;
	if (keycode == 0)
		all->inputs.moveleft = 0;
	if (keycode == 2)
		all->inputs.moveright = 0;
	return (0);
}

void	setdefault(t_all *all)
{
	all->inputs.rightturn = 0;
	all->inputs.leftturn = 0;
	all->inputs.moveforward = 0;
	all->inputs.movebackward = 0;
	all->inputs.moveright = 0;
	all->inputs.moveleft = 0;
	all->plr.movespeed = 0.1;
	all->mapon = 1;
	all->win.win = mlx_new_window(all->win.mlx, all->win.w_width, \
	all->win.w_height, "Cub3D");
}

void	setimages(t_all *all)
{
	all->display.img = mlx_new_image(all->win.mlx, all->win.w_width,
			all->win.w_height);
	all->display.addr = (int *)mlx_get_data_addr(all->display.img,
			&all->display.bpp, &all->display.line_l, &all->display.en);
	all->display.height = all->win.w_height;
	all->minimap.img = mlx_new_image(all->win.mlx,
			all->win.w_width, all->win.w_height);
	all->minimap.addr = (int *)mlx_get_data_addr(all->minimap.img,
			&all->minimap.bpp, &all->minimap.line_l, &all->minimap.en);
	all->maprays.img = mlx_new_image(all->win.mlx,
			all->win.w_width, all->win.w_height);
	all->maprays.addr = (int *)mlx_get_data_addr(all->maprays.img,
			&all->maprays.bpp, &all->maprays.line_l, &all->maprays.en);
}
