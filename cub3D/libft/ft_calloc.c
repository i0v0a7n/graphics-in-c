/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:18:54 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/09 19:22:47 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = malloc(count * size);
	if (buffer == 0)
		return (0);
	while (i < count * size)
		buffer[i++] = 0;
	return ((void *)buffer);
}
