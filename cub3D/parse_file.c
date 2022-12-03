/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:22:21 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/05 18:17:25 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	read_file(t_all *all, int fd)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	line = make_line(fd);
	close(fd);
	all->file = ft_split(line, '\n');
	free(line);
	i = 0;
	while (all->file[i])
	{
		ret = parse_line(all, all->file[i]);
		if (ret == 1)
			return (1);
		else if (ret == -1)
			return (set_map_params(all, i));
		i++;
	}
	printf("no map found in file\n");
	return (1);
}

int	open_file(t_all *all, char *map)
{
	int	fd;
	int	i;

	i = 0;
	if (ft_strlen(map) < 4)
	{
		printf("bad map format %s\n", map);
		return (1);
	}
	if (!(map[ft_strlen(map) - 1] == 'b' && \
		map[ft_strlen(map) - 2] == 'u' && \
		map[ft_strlen(map) - 3] == 'c' && \
		map[ft_strlen(map) - 4] == '.'))
	{
		printf("bad map format: %s\n", map);
		return (1);
	}
	fd = open(map, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		printf("error opening map file %s\n", map);
		return (1);
	}
	return (read_file(all, fd));
}
