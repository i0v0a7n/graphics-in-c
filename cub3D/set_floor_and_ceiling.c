/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_and_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:45:59 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/30 18:16:39 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	otval_polosok(char c)
{
	printf("invalid parametes in %c\n", c);
	return (1);
}

int	get_rgb(const char *str, int *i)
{
	int	ret;

	while (str[*i] == ' ')
		*i += 1;
	if (str[*i] < '0' || str[*i] > '9')
	{
		printf("extra stuff in RGB color\n");
		return (-1);
	}
	ret = ft_atoi(str + *i);
	if (ret < 0 || ret > 255)
	{
		printf("color out of range: %d\n", ret);
		return (-1);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
	while (str[*i] == ' ')
		*i += 1;
	return (ret);
}

int	set_floor(t_all *all, const char *line, int i)
{
	int	ret;
	int	buf;

	ret = get_rgb(line, &i) * 256 * 256;
	if (line[i] != ',' || ret < 0)
		return (otval_polosok('F'));
	i++;
	buf = get_rgb(line, &i) * 256;
	ret += buf;
	if (line[i] != ',' || buf < 0)
		return (otval_polosok('F'));
	i++;
	buf = get_rgb(line, &i);
	ret += buf;
	if (line[i] != 0)
		return (otval_polosok('F'));
	all->c_floor = ret;
	return (0);
}

int	set_ceiling(t_all *all, const char *line, int i)
{
	int	ret;
	int	buf;

	ret = get_rgb(line, &i) * 256 * 256;
	if (line[i] != ',' || ret < 0)
		return (otval_polosok('C'));
	i++;
	buf = get_rgb(line, &i) * 256;
	ret += buf;
	if (line[i] != ',' || buf < 0)
		return (otval_polosok('C'));
	i++;
	buf = get_rgb(line, &i);
	ret += buf;
	if (line[i] != 0)
		return (otval_polosok('C'));
	all->c_ceiling = ret;
	return (0);
}

int	set_bars(t_all *all, const char *line, int i)
{
	if (line[i++] == 'F')
	{
		if (line[i] != ' ')
		{
			printf("no space after F\n");
			return (1);
		}
		if (all->c_floor < 0)
			return (set_floor(all, line, i));
		printf("redefenition of floor\n");
		return (1);
	}
	else
	{
		if (line[i] != ' ')
		{
			printf("no space after C\n");
			return (1);
		}
		if (all->c_ceiling < 0)
			return (set_ceiling(all, line, i));
		printf("redefenition of ceiling\n");
		return (1);
	}
}
