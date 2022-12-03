/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:31:14 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 16:02:01 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_stuff(t_all *all)
{
	int	sprite_count;
	int	plr;
	int	i;
	int	j;

	sprite_count = 0;
	plr = 0;
	i = -1;
	all->sprites = malloc(sizeof(t_sprite) * all->sprite_amount);
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (ft_strchr("NSWE20", all->map[i][j]) && is_seal(all, i, j) == 1)
				return (1);
			if (ft_strchr("NSWE", all->map[i][j]) && pl_pos(all, i, j) == 1)
				return (1);
			else if (all->map[i][j] == '2')
				sprite_check(all, i, j, &sprite_count);
		}
	}
	return (player_check(all));
}

int	check_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j] != 0)
		{
			if (!(ft_strchr("210NSWE ", all->map[i][j])))
			{
				printf("illegal symbol in map %c\n", all->map[i][j]);
				return (1);
			}
			if (all->map[i][j] == '2')
				all->sprite_amount++;
			j++;
		}
		i++;
	}
	return (check_stuff(all));
}

int	make_map(t_all *all, int i)
{
	char	*model;
	int		j;
	char	**map;

	map = all->file;
	j = 0;
	model = set_model(all->m_length);
	all->map = malloc(sizeof(char *) * (all->m_height + 1));
	while (map[i])
	{
		all->map[j] = line_with_spaces(model, map[i]);
		i++;
		j++;
	}
	all->map[j] = 0;
	free(model);
	return (check_map(all));
}

int	set_map_params(t_all *all, int i)
{
	int		j;
	char	**map;

	map = all->file;
	j = i;
	while (map[j])
	{
		if (!(ft_strchr(map[j], '1')))
		{
			printf("something went terribly wrong with map\n");
			return (1);
		}
		if ((int)ft_strlen(map[j]) > all->m_length)
			all->m_length = ft_strlen(map[j]);
		all->m_height++;
		j++;
	}
	return (make_map(all, i));
}
