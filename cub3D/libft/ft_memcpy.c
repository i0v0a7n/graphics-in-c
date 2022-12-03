/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:25:54 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/29 17:43:31 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (src == NULL && dst == NULL)
		return (0);
	p = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*p++ = *(unsigned char *)src++;
		i++;
	}
	return ((void *)dst);
}
