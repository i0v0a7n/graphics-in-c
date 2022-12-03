/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:43:19 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/05 19:54:41 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	movements_2(t_all *all)
{
	if (all->inputs.moveforward == 1 && all->map[(int)(all->plr.yorigin + \
	sin(all->plr.dir) * all->plr.movespeed * 2)] \
	[(int)(all->plr.xorigin)] == '0')
		all->plr.yorigin += sin(all->plr.dir) * all->plr.movespeed;
	if (all->inputs.moveleft == 1 && all->map[(int)(all->plr.yorigin)] \
	[(int)((all->plr.xorigin - \
	cos(all->plr.dir + M_PI / 2) * all->plr.movespeed * 2))] == '0')
		all->plr.xorigin -= cos(all->plr.dir + M_PI / 2) * all->plr.movespeed;
	if (all->inputs.moveleft == 1 && all->map[(int)((all->plr.yorigin - \
	sin(all->plr.dir + M_PI / 2) * all->plr.movespeed * 2))] \
	[(int)(all->plr.xorigin)] == '0')
		all->plr.yorigin -= sin(all->plr.dir + M_PI / 2) * all->plr.movespeed;
	if (all->inputs.moveright == 1 && all->map[(int)(all->plr.yorigin)] \
	[(int)((all->plr.xorigin + \
	cos(all->plr.dir + M_PI / 2) * all->plr.movespeed * 2))] == '0')
		all->plr.xorigin += cos(all->plr.dir + M_PI / 2) * all->plr.movespeed;
	if (all->inputs.moveright == 1 && all->map[(int)(all->plr.yorigin + \
	sin(all->plr.dir + M_PI / 2) * all->plr.movespeed * 2)] \
	[(int)(all->plr.xorigin)] == '0')
		all->plr.yorigin += sin(all->plr.dir + M_PI / 2) * all->plr.movespeed;
}

void	movements(t_all *all)
{
	if (all->plr.dir > 2 * M_PI)
		all->plr.dir -= 2 * M_PI;
	if (all->plr.dir < 0)
		all->plr.dir += 2 * M_PI;
	if (all->inputs.rightturn == 1)
		all->plr.dir += M_PI / 120;
	if (all->inputs.leftturn == 1)
		all->plr.dir -= M_PI / 120;
	if (all->inputs.movebackward == 1 && \
	all->map[(int)(all->plr.yorigin)][(int)((all->plr.xorigin - \
	cos(all->plr.dir) * all->plr.movespeed * 2))] == '0')
		all->plr.xorigin -= cos(all->plr.dir) * all->plr.movespeed;
	if (all->inputs.movebackward == 1 && all->map[(int)((all->plr.yorigin - \
	sin(all->plr.dir) * all->plr.movespeed * 2))] \
	[(int)(all->plr.xorigin)] == '0')
		all->plr.yorigin -= sin(all->plr.dir) * all->plr.movespeed;
	if (all->inputs.moveforward == 1 && \
	all->map[(int)(all->plr.yorigin)][(int)((all->plr.xorigin + \
	cos(all->plr.dir) * all->plr.movespeed * 2))] == '0')
		all->plr.xorigin += cos(all->plr.dir) * all->plr.movespeed;
	movements_2(all);
}
