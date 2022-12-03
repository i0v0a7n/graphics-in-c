/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:21:32 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/29 17:34:11 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	buf;

	i = 0;
	j = 0;
	while (dst[i] != 0 && i < dstsize)
		i++;
	buf = i;
	while (src[j] != 0 && (i + 1) < dstsize)
		dst[i++] = src[j++];
	if (i < dstsize)
		dst[i] = 0;
	return (buf + ft_strlen(src));
}
