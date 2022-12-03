/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:56:32 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 17:38:12 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	nospace(const char *line)
{
	printf("no space in line %s\n", line);
	return (1);
}

int	set_by_side(t_all *all, char *subline, int side)
{
	if (side == 1)
		return (set_north(all, subline));
	else if (side == 2)
		return (set_south(all, subline));
	else if (side == 3)
		return (set_east(all, subline));
	else if (side == 4)
		return (set_west(all, subline));
	else if (side == 5)
		return (set_sprite(all, subline));
	else
		return (1);
}

int	set_texture(t_all *all, const char *line, int i, int side)
{
	int		j;

	j = 0;
	if (line[++i] != ' ')
		return (nospace(line));
	while (line[i] == ' ')
		i++;
	if (line[i] == 0)
	{
		printf("no texture\n");
		return (1);
	}
	j = i;
	while (line[j] != ' ' && line[j] != 0)
		j++;
	if (line[j] != 0)
	{
		printf("extra stuff in texture\n");
		return (1);
	}
	return (set_by_side(all, (char *)(line + i), side));
}

int	set_side(t_all *all, const char *line, int i)
{
	if (line[i] == 'N')
	{
		if (line[++i] == 'O')
			return (set_texture(all, line, i, 1));
	}
	else if (line[i] == 'W')
	{
		if (line[++i] == 'E')
			return (set_texture(all, line, i, 4));
	}
	else if (line[i] == 'S')
	{
		if (line[++i] == 'O')
			return (set_texture(all, line, i, 2));
		else
			return (set_texture(all, line, i - 1, 5));
	}
	else if (line[i] == 'E')
	{
		if (line[++i] == 'A')
			return (set_texture(all, line, i, 3));
	}
	printf("no match found\n");
	return (1);
}

int	set_resolution(t_all *all, const char *line, int i)
{
	i++;
	while (line[i] == ' ')
		i++;
	if (line[i] == 0)
		return (1);
	all->win.w_width = ft_atoi(line + i);
	while (line[i] <= '9' && line[i] >= '0')
		i++;
	if (line[i] != ' ')
		return (1);
	while (line[i] == ' ')
		i++;
	all->win.w_height = ft_atoi(line + i);
	while (line[i] <= '9' && line[i] >= '0')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		return (1);
	else
		return (0);
}
