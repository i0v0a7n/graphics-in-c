/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:19:36 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/07 18:36:53 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- != 0)
	{
		if ((unsigned char)c == *(unsigned char *)src)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src;
			return (dst);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (0);
}
