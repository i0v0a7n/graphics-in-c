/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:03:37 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 15:50:52 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	calculate_offset(t_all *all, int spritenum, int size)
{
	double	dir;
	int		ret;

	dir = atan2(all->sprites[spritenum].y - all->plr.yorigin, \
	all->sprites[spritenum].x - all->plr.xorigin) - all->plr.dir;
	if (dir < -M_PI)
		dir += 2 * M_PI;
	if (dir > M_PI)
		dir -= 2 * M_PI;
	ret = dir * all->win.w_width * 3 / M_PI + (all->win.w_width \
	- size) / 2;
	return (ret);
}

int	get_pixel_color(t_all *all, int i, int j, int size)
{
	int	color;

	color = all->sprite.addr[(int)(j * all->sprite.height \
	/ size) *\
	(all->sprite.line_l / 4) + (int)(i *\
	all->sprite.line_l / (size * 4))];
	return (color);
}

void	put_sprite(t_all *all, double *zbuf, int spritenum)
{
	int	i;
	int	j;
	int	size;
	int	h_offset;
	int	v_offset;

	i = -1;
	size = (all->win.w_height / \
	all->sprites[spritenum].distance * 2);
	h_offset = calculate_offset(all, spritenum, size);
	v_offset = (all->win.w_height - size) / 2;
	while (++i < size)
	{
		j = -1;
		if (!(h_offset + i < 0 || h_offset + i >= all->win.w_width))
		{
			while (++j < size)
				if (!(v_offset + j < 0 || v_offset + j >= all->win.w_height) \
				&& all->sprites[spritenum].distance < zbuf[h_offset + i] \
				&& get_pixel_color(all, i, j, size) != (int)0xFF000000)
					my_mlx_pixel_put(&all->display, h_offset + i, v_offset + \
					j, get_pixel_color(all, i, j, size));
		}
	}
}

void	sprites(t_all *all, double *zbuf)
{
	int	spritenum;

	spritenum = 0;
	while (spritenum < all->sprite_amount)
	{
		all->sprites[spritenum].distance = sqrt(pow(all->plr.xorigin \
		- all->sprites[spritenum].x, 2) + pow(all->plr.yorigin - \
		all->sprites[spritenum].y, 2));
		spritenum++;
	}
	bubble_sort(all);
	spritenum = 0;
	while (spritenum < all->sprite_amount)
	{
		put_sprite(all, zbuf, spritenum);
		spritenum++;
	}
}

void	ft_cast_ray(t_all *all)
{
	double	*zbuf;
	int		i;
	double	ddx;
	double	ddy;
	double	*lengths;

	zbuf = malloc(all->win.w_width * sizeof(double));
	lengths = malloc(sizeof(double) * 3);
	i = -1;
	while (++i < all->win.w_width)
	{
		shave_lines(all, &ddx, &ddy, i);
		minimap_rays(all, ddx, ddy);
		cast_xrays(all, ddx, ddy, &lengths);
		cast_yrays(all, ddx, ddy, &lengths);
		if (lengths[0] < lengths[1])
			put_vertical(all, lengths, &zbuf[i], i);
		else
			put_horizontal(all, lengths, &zbuf[i], i);
	}
	free(lengths);
	sprites(all, zbuf);
	free(zbuf);
}
