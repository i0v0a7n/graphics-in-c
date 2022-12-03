/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:31:12 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 18:30:02 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	swap(t_sprite *a, t_sprite *b)
{
	t_sprite	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	bubble_sort(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->sprite_amount - 1)
	{
		j = i + 1;
		while (j < all->sprite_amount)
		{
			if (all->sprites[j].distance > all->sprites[i].distance)
				swap(&all->sprites[j], &all->sprites[i]);
			j++;
		}
		i++;
	}
}

int	args_err(void)
{
	printf("wrong arguments supplied\n");
	return (1);
}
