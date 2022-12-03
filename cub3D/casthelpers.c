/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casthelpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:25:46 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 15:59:19 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap_rays(t_all *all, double ddx, double ddy)
{
	int	ray;

	ray = 0;
	while (ray++ < 50)
	{
		if (ft_strchr(" 1", \
		all->map[(int)(all->plr.y)][(int)(all->plr.x)]) == 0)
		{
			all->plr.x += ddx;
			all->plr.y += ddy;
			my_mlx_pixel_put(&all->maprays, all->plr.x * all->mm_scale, \
			all->plr.y * all->mm_scale, 0x55999999);
		}
	}
	all->plr.x = all->plr.xorigin;
	all->plr.y = all->plr.yorigin;
}

void	set_dxdy(double ddx, double ddy, double *dx, double *dy)
{
	*dx = 1000;
	*dy = 1000;
	if (ddy != 0)
		*dx = 1 / ddy * ddx;
	if (ddx != 0)
		*dy = 1 / ddx * ddy;
}

void	shave_lines(t_all *all, double *ddx, double *ddy, int i)
{
	all->plr.x = all->plr.xorigin;
	all->plr.y = all->plr.yorigin;
	*ddx = cos(all->plr.dir - (all->win.w_width / 2 - i) * all->grad) / 30;
	*ddy = sin(all->plr.dir - (all->win.w_width / 2 - i) * all->grad) / 30;
}

void	put_vertical(t_all *all, double *lengths, double *zbuf, int i)
{
	*zbuf = lengths[0];
	lengths[0] *= cos((all->win.w_width / 2 - i) * all->grad);
	if (cos(all->plr.dir - (all->win.w_width / 2 - i) * all->grad) < 0)
	{
		all->pair.texture = all->txrw;
		ft_stripe(i, lengths[0], &all->pair, (int)(-lengths[2] * \
		all->pair.texture.line_l / 4) % (all->pair.texture.line_l / 4));
	}
	else
	{
		all->pair.texture = all->txre;
		ft_stripe(i, lengths[0], &all->pair, (int)(lengths[2] * \
		all->pair.texture.line_l / 4) % (all->pair.texture.line_l / 4));
	}
}

void	put_horizontal(t_all *all, double *lengths, double *zbuf, int i)
{
	*zbuf = lengths[1];
	lengths[1] *= cos((all->win.w_width / 2 - i) * all->grad);
	if (sin(all->plr.dir - (all->win.w_width / 2 - i) * all->grad) < 0)
	{
		all->pair.texture = all->txrn;
		ft_stripe(i, lengths[1], &all->pair, (int)(all->plr.x * \
		all->pair.texture.line_l / 4) % (all->pair.texture.line_l / 4));
	}
	else
	{
		all->pair.texture = all->txrs;
		ft_stripe(i, lengths[1], &all->pair, (int)(-(all->plr.x) * \
		all->pair.texture.line_l / 4) % (all->pair.texture.line_l / 4));
	}
}
