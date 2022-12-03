/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_as_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:29:57 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/06 17:40:44 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*make_line(int fd)
{
	char	*buf3;
	char	*buf2;
	char	*buf;
	int		ret;

	buf2 = malloc(65);
	buf = malloc(1);
	buf[0] = '\0';
	ret = (1);
	while (ret > 0)
	{
		buf3 = ft_strdup(buf);
		free(buf);
		ret = read(fd, buf2, 64);
		buf2[ret] = '\0';
		buf = ft_strjoin(buf3, buf2);
		free(buf3);
	}
	free(buf2);
	return (buf);
}

char	*line_with_spaces(char *spaces, char *line)
{
	int		i;
	char	*buf;

	buf = ft_strdup(spaces);
	i = 0;
	while (i < (int)ft_strlen(line))
	{
		buf[i] = line[i];
		i++;
	}
	return (buf);
}

char	*set_model(int length)
{
	char	*buf;
	int		i;

	buf = malloc(length + 1);
	i = 0;
	while (i < length)
		buf[i++] = ' ';
	buf[i] = '\0';
	return (buf);
}
