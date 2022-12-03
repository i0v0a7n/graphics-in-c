/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainhelpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:29:15 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 18:31:11 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	krestik(void)
{
	exit (0);
	return (0);
}

void	clear_struct(t_all *all)
{
	all->win.mlx = mlx_init();
	all->c_ceiling = -1;
	all->c_floor = -1;
	all->plr.xorigin = 0;
	all->txre.img = 0;
	all->txrn.img = 0;
	all->txrs.img = 0;
	all->txrw.img = 0;
	all->sprite.img = 0;
	all->m_height = 0;
	all->win.w_height = 0;
	all->win.w_width = 0;
}

int	no_args_err(void)
{
	printf("no arguments found\n");
	return (1);
}

int	general_error(void)
{
	printf("error!\n");
	return (1);
}

void	shrink_screen(t_all *all)
{
	int	screen_height;
	int	screen_width;

	mlx_get_screen_size(&screen_width, &screen_height);
	if (screen_height < all->win.w_height)
		all->win.w_height = screen_height;
	if (screen_width < all->win.w_width)
		all->win.w_width = screen_width;
	all->grad = M_PI / (all->win.w_width * 3);
	all->mm_scale = (int)(all->win.w_height / (all->m_height + 10));
	if ((int)(all->win.w_width / (all->m_length + 10) < all->mm_scale))
		all->mm_scale = (int)(all->win.w_width / (all->m_length + 10));
	if (all->mm_scale < 3)
		all->mm_scale = 3;
}
