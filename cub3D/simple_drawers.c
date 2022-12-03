/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_drawers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:12:32 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/21 17:13:41 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (void *)img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_red_square(int x, int y, int width, t_img img)
{
	int		i;
	int		j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < width)
		{
			my_mlx_pixel_put(&img, x + j, y + i, 0x55FF0000);
		}
	}
}

void	ft_put_yellow_square(int x, int y, int width, t_img img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < width)
		{
			my_mlx_pixel_put(&img, x + j, y + i, 0x55FFFF00);
		}
	}
}
