/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_drawers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:19:52 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 16:51:50 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_make_transparent(int width, int height, t_img img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(&img, j, i, 0xFF000000);
	}
}

void	ft_put_opacity_square(t_all *all)
{
	int	i;
	int	j;

	i = (int)((all->plr.yorigin - 2) * all->mm_scale) - 1;
	while (++i < (int)((all->plr.yorigin + 2) * all->mm_scale))
	{
		j = (int)((all->plr.xorigin - 2) * all->mm_scale) - 1;
		while (++j < (int)((all->plr.xorigin + 2) * all->mm_scale))
			if (j < all->win.w_width && i < all->win.w_height)
				my_mlx_pixel_put(&all->maprays, j, i, 0xFF000000);
	}
}

void	ft_print_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->map[i])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == '1')
				ft_put_red_square(j * all->mm_scale + 1,
					i * all->mm_scale + 1, all->mm_scale - 1, all->minimap);
			else if (all->map[i][j] == '2')
				ft_put_yellow_square(j * all->mm_scale + 1,
					i * all->mm_scale + 1, all->mm_scale - 1, all->minimap);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_nullify(t_img img, int floor, int ceiling)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img.height / 2)
	{
		j = -1;
		while (++j < img.line_l / 4)
			my_mlx_pixel_put(&img, j, i, ceiling);
	}
	while (++i < img.height)
	{
		j = -1;
		while (++j < img.line_l / 4)
			my_mlx_pixel_put(&img, j, i, floor);
	}
}

void	ft_stripe(int step, double distance, t_pair *pair, int offset)
{
	int				j;
	int				stop;
	unsigned int	color;
	int				skip;

	j = 0;
	if (distance > 0)
		j = (pair->img.height / distance);
	skip = -j;
	if (j > pair->img.height / 2 || j == 0)
		(j = pair->img.height / 2);
	stop = -j;
	while (j-- > stop)
	{
		color = pair->texture.addr[(int)((j - skip) * distance * \
		pair->texture.height / (2 * pair->img.height)) *\
		pair->texture.line_l / 4 + offset];
		if (color != 0xFF000000)
			my_mlx_pixel_put(&(pair->img), step, j \
			+ pair->img.height / 2, color);
	}
}
