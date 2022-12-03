/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:35:04 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/14 14:08:11 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	_Bool	stas;

	stas = 0;
	while (*s != 0)
	{
		if ((char)c == *s)
			stas = 1;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	if (stas == 0)
		return (0);
	while (*s != (char)c)
		s--;
	return ((char *)s);
}
