/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:01:43 by sfrey             #+#    #+#             */
/*   Updated: 2021/06/18 16:19:18 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 2 || argc > 4 || !(argv[1][0] == 'M' || argv[1][0] == 'J' || \
	argv[1][0] == 'B') || argv[1][1] != 0)
		return (no_args_output());
	clear_struct(&all);
	all.display.img = mlx_new_image(\
	all.win.mlx, all.win.w_width, all.win.w_height);
	all.display.addr = mlx_get_data_addr(\
	all.display.img, &all.display.bpp, &all.display.line_l, &all.display.en);
	all.display.height = all.win.w_height;
	all.display.line_l = all.win.w_width * 4;
	set_fractal(&all, argc, argv);
	calculate(&all);
	mlx_put_image_to_window(all.win.mlx, all.win.win, all.display.img, 0, 0);
	mlx_hook(all.win.win, 17, 1L << 0, krestik, &all);
	mlx_key_hook(all.win.win, key_hook, &all);
	mlx_hook(all.win.win, 4, 1L << 2, mouse_press, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
/*gcc libmlx.a libft.a *c -Imlx -framework OpenGL -framework AppKit*/
