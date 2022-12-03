/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sides.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:44:39 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 16:24:03 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	set_north(t_all *all, char *subline)
{
	if (all->txrn.img != NULL)
	{
		printf("NO: redefenition of texture\n");
		return (1);
	}
	all->txrn.img = mlx_xpm_file_to_image(
			all->win.mlx, subline, &all->txrn.line_l, &all->txrn.height);
	if (all->txrn.img == NULL)
	{
		printf("NO: no such texture exists\n");
		return (1);
	}
	all->txrn.addr = (int *)mlx_get_data_addr(
			all->txrn.img, &all->txrn.bpp, &all->txrn.line_l, &all->txrn.en);
	return (0);
}

int	set_south(t_all *all, char *subline)
{
	if (all->txrs.img != NULL)
	{
		printf("SO: redefenition of texture\n");
		return (1);
	}
	all->txrs.img = mlx_xpm_file_to_image(
			all->win.mlx, subline, &all->txrs.line_l, &all->txrs.height);
	if (all->txrs.img == NULL)
	{
		printf("SO: no such texture exists\n");
		return (1);
	}
	all->txrs.addr = (int *)mlx_get_data_addr(
			all->txrs.img, &all->txrs.bpp, &all->txrs.line_l, &all->txrs.en);
	return (0);
}

int	set_east(t_all *all, char *subline)
{
	if (all->txre.img != NULL)
	{
		printf("EA: redefenition of texture\n");
		return (1);
	}
	all->txre.img = mlx_xpm_file_to_image(
			all->win.mlx, subline, &all->txre.line_l, &all->txre.height);
	if (all->txre.img == NULL)
	{
		printf("EA: no such texture exists\n");
		return (1);
	}
	all->txre.addr = (int *)mlx_get_data_addr(
			all->txre.img, &all->txre.bpp, &all->txre.line_l, &all->txre.en);
	return (0);
}

int	set_west(t_all *all, char *subline)
{
	if (all->txrw.img != NULL)
	{
		printf("WE: redefenition of texture\n");
		return (1);
	}
	all->txrw.img = mlx_xpm_file_to_image(
			all->win.mlx, subline, &all->txrw.line_l, &all->txrw.height);
	if (all->txrw.img == NULL)
	{
		printf("WE: no such texture exists\n");
		return (1);
	}
	all->txrw.addr = (int *)mlx_get_data_addr(
			all->txrw.img, &all->txrw.bpp, &all->txrw.line_l, &all->txrw.en);
	return (0);
}

int	set_sprite(t_all *all, char *subline)
{
	if (all->sprite.img != NULL)
	{
		printf("S: redefenition of texture\n");
		return (1);
	}
	all->sprite.img = mlx_xpm_file_to_image(
			all->win.mlx, subline, &all->sprite.line_l, &all->sprite.height);
	if (all->sprite.img == NULL)
	{
		printf("S: no such texture exists\n");
		return (1);
	}
	all->sprite.addr = (int *)mlx_get_data_addr(
			all->sprite.img, &all->sprite.bpp,
			&all->sprite.line_l, &all->sprite.en);
	return (0);
}
