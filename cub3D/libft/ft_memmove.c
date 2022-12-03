/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:38:37 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/29 17:42:17 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;
	size_t			pos;

	if (src == NULL && dst == NULL)
		return (0);
	p = (unsigned char *)dst;
	s = (unsigned char *)src;
	pos = (int)dst;
	i = 0;
	if (s > p)
	{
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
	}
	else
		while (len--)
			p[len] = s[len];
	return (dst);
}
