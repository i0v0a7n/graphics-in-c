/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycaster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:24:59 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 17:39:09 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_inity(t_all *all, double ddy, double dx)
{
	if (ddy > 0)
		all->plr.y = (int)all->plr.yorigin + 1;
	else
		all->plr.y = (int)all->plr.yorigin;
	all->plr.x = all->plr.xorigin + dx * (all->plr.y - all->plr.yorigin);
}

void	set_ylength(t_all *all, double **lengths)
{
	(*lengths)[1] = 1024;
	if ((int)(all->plr.y) > 0 && (int)(all->plr.x) > 0 \
	&& (int)(all->plr.y) < all->m_height && (int)(all->plr.x) < all->m_length)
		(*lengths)[1] = sqrt((all->plr.x - all->plr.xorigin) * \
		(all->plr.x - all->plr.xorigin) + (all->plr.y - all->plr.yorigin) * \
		(all->plr.y - all->plr.yorigin));
}

void	cast_yrays(t_all *all, double ddx, double ddy, double **lengths)
{
	double	dx;
	double	dy;

	set_dxdy(ddx, ddy, &dx, &dy);
	set_inity(all, ddy, dx);
	while ((int)(all->plr.y) > 0 && (int)(all->plr.x) \
	> 0 && (int)(all->plr.y) < all->m_height && \
	(int)(all->plr.x) < all->m_length)
	{
		if ((strchr(" 1", all->map[(int)(all->plr.y)][(int)(all->plr.x)]) \
		> 0 && ddy > 0) || (strchr(" 1", all->map[(int)(all->plr.y - \
		0.001)][(int)(all->plr.x)]) > 0 && ddy < 0))
			break ;
		if (ddy > 0)
		{
			all->plr.y++;
			all->plr.x += dx;
		}
		else
		{
			all->plr.y--;
			all->plr.x -= dx;
		}
	}
	set_ylength(all, lengths);
}
