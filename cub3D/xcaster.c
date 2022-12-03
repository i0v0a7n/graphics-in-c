/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcaster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:24:08 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 17:38:43 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_xlength(t_all *all, double **lengths)
{
	(*lengths)[0] = 1024;
	(*lengths)[2] = 0;
	if ((int)(all->plr.y) > 0 && (int)(all->plr.x) > 0 &&
		(int)(all->plr.y) < all->m_height && (int)(all->plr.x) < all->m_length)
	{
		(*lengths)[0] = sqrt((all->plr.x - all->plr.xorigin) * (all->plr.x - \
		all->plr.xorigin) + (all->plr.y - all->plr.yorigin) * (all->plr.y - \
		all->plr.yorigin));
		(*lengths)[2] = all->plr.y;
	}
}

void	set_initx(t_all *all, double ddx, double dy)
{
	if (ddx > 0)
		all->plr.x = (int)all->plr.xorigin + 1;
	else
		all->plr.x = (int)all->plr.xorigin;
	all->plr.y = all->plr.yorigin + dy * (all->plr.x - all->plr.xorigin);
}

void	cast_xrays(t_all *all, double ddx, double ddy, double **lengths)
{
	double	dx;
	double	dy;

	set_dxdy(ddx, ddy, &dx, &dy);
	set_initx(all, ddx, dy);
	while ((int)(all->plr.y) > 0 && (int)(all->plr.x) > 0 && \
	(int)(all->plr.y) < all->m_height && (int)(all->plr.x) < all->m_length)
	{
		if ((ft_strchr(" 1", all->map[(int)(all->plr.y)][(int)(all->plr.x)]) \
		> 0 && ddx > 0) || (strchr(" 1", all->map[(int)(all->plr.y)] \
		[(int)(all->plr.x - 0.001)]) > 0 && ddx < 0))
			break ;
		if (ddx > 0)
		{
			all->plr.x++;
			all->plr.y += dy;
		}
		else
		{
			all->plr.x--;
			all->plr.y -= dy;
		}
	}
	set_xlength(all, lengths);
}
