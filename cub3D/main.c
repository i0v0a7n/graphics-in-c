/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:01:43 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 16:52:03 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	helper(t_all *all)
{
	movements(all);
	ft_nullify(all->display, all->c_floor, all->c_ceiling);
	ft_put_opacity_square(all);
	ft_cast_ray(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->display.img, 0, 0);
	save_screen(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	clear_struct(&all);
	if (argc < 2)
		return (no_args_err());
	if (open_file(&all, argv[1]) != 0)
		return (general_error());
	shrink_screen(&all);
	setdefault(&all);
	setimages(&all);
	ft_make_transparent(all.win.w_width, all.win.w_height, all.minimap);
	ft_make_transparent(all.win.w_width, all.win.w_height, all.maprays);
	ft_print_map(&all);
	all.pair.img = all.display;
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		return (helper(&all));
	if (argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save", 7)))
		return (args_err());
	mlx_hook(all.win.win, 2, 1L << 0, openboi, &all);
	mlx_hook(all.win.win, 3, 1L << 1, closeboi, &all);
	mlx_hook(all.win.win, 17, 1L << 0, krestik, &all);
	mlx_loop_hook(all.win.mlx, render_next_frame, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
