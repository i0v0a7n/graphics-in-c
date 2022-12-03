/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:18:06 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/04 20:24:46 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_all_set(t_all *all)
{
	if (all->c_ceiling == -1 || all->c_floor == -1)
	{
		printf("floor or ceiling is not set\n");
		return (1);
	}
	if (!(all->txre.img > 0 && all->txrw.img > 0
			&& all->txrs.img > 0 && all->txrn.img > 0))
	{
		printf("missing wall textures in .cub\n");
		return (1);
	}
	if (!(all->sprite.img > 0))
	{
		printf("missing sprite in .cub\n");
		return (1);
	}
	if (!(all->win.w_width >= 320
			&& all->win.w_height >= 240))
	{
		printf("resolution should be at least 320x240\n");
		return (1);
	}
	return (0);
}

int	parse_setting(t_all *all, char *line, int i)
{
	if (line[i] == 'R')
	{
		if (all->win.w_width != 0)
		{
			printf("redefenition of resolution %d %d\n", \
			all->win.w_width, all->win.w_height);
			return (1);
		}
		if (line[i + 1] != ' ')
		{
			printf("need a space after R\n");
		}
		return (set_resolution(all, line, i));
	}
	else if (strchr("NWSE", line[i]))
		return (set_side(all, line, i));
	return (set_bars(all, line, i));
}

int	parse_line(t_all *all, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 0)
		return (0);
	else if (strchr("RNWSEFC", line[i]))
		return (parse_setting(all, line, i));
	else if (line[i] == '1')
	{
		if (is_all_set(all) == 0)
			return (-1);
		printf("missing some settings\n");
		return (1);
	}
	printf("extra settings\n");
	return (1);
}
