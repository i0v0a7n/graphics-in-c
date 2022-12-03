/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shooter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:36:15 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 18:43:39 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	write_header(unsigned char *header, t_all *all)
{
	size_t	fsize;

	if (all->win.w_width % 4)
		all->win.w_width -= all->win.w_width % 4;
	fsize = all->win.w_height * all->win.w_width + 54;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)fsize;
	header[3] = (unsigned char)(fsize >> 8);
	header[4] = (unsigned char)(fsize >> 16);
	header[5] = (unsigned char)(fsize >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)all->win.w_width;
	header[19] = (unsigned char)(all->win.w_width >> 8);
	header[20] = (unsigned char)(all->win.w_width >> 16);
	header[21] = (unsigned char)(all->win.w_width >> 24);
	header[22] = (unsigned char)(all->win.w_height);
	header[23] = (unsigned char)(all->win.w_height >> 8);
	header[24] = (unsigned char)(all->win.w_height >> 16);
	header[25] = (unsigned char)(all->win.w_height >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
}

void	write_img_colors(int fd, t_all *all)
{
	int	x;
	int	y;
	int	*color;

	y = all->win.w_height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < all->win.w_width)
		{
			color = all->display.addr + (y * all->win.w_width + \
			x * (all->display.bpp / 32));
			write(fd, (void *)color, 3);
		}
	}
}

void	save_screen(t_all *all)
{
	unsigned char	*header;
	int				fd;

	header = (unsigned char *)ft_calloc(1, 54);
	if (header == 0)
	{
		printf("Something went terribly wrong\n");
		exit(0);
	}
	write_header(header, all);
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		printf("failed to create BMP\n");
		exit(0);
	}
	write(fd, header, 54);
	free(header);
	write_img_colors(fd, all);
	close(fd);
	exit(0);
}
