/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:57:36 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 17:42:54 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_seal(t_all *all, int i, int j)
{
	if (i == 0 || i == (int)all->m_height - 1 || j == 0 || \
	j + 1 == (int)ft_strlen(all->map[i]))
	{
		printf("map is not sealed\n%s\n", all->map[i]);
		return (1);
	}
	if ((int)ft_strlen(all->map[i - 1]) <= j || \
	(int)ft_strlen(all->map[i + 1]) <= j)
	{
		printf("map is not sealed\n%s\n", all->map[i]);
		return (1);
	}
	if (!(ft_strchr("210NSWE", all->map[i][j - 1]) && \
		ft_strchr("210NSWE", all->map[i][j + 1]) && \
		ft_strchr("210NSWE", all->map[i - 1][j]) && \
		ft_strchr("210NSWE", all->map[i + 1][j])))
	{
		printf("map is not sealed\n%s\n", all->map[i]);
		return (1);
	}
	return (0);
}

int	pl_pos(t_all *all, int i, int j)
{
	if (all->plr.xorigin != 0)
	{
		printf("redefenition of plr position\n");
		return (1);
	}
	if (all->map[i][j] == 'W')
		all->plr.dir = M_PI;
	else if (all->map[i][j] == 'E')
		all->plr.dir = 0;
	else if (all->map[i][j] == 'S')
		all->plr.dir = M_PI / 2;
	else if (all->map[i][j] == 'N')
		all->plr.dir = -M_PI / 2;
	all->plr.xorigin = j + 0.5;
	all->plr.yorigin = i + 0.5;
	all->map[i][j] = '0';
	return (0);
}

void	sprite_check(t_all *all, int i, int j, int *sprite_count)
{
	all->sprites[*sprite_count].x = j + 0.5;
	all->sprites[*sprite_count].y = i + 0.5;
	all->sprites[*sprite_count].texture = all->sprite;
	(*sprite_count)++;
}

int	player_check(t_all *all)
{
	if (all->plr.xorigin == 0)
	{
		printf("player is not set\n");
		return (1);
	}
	return (0);
}
