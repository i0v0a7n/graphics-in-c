/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:16:29 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/16 16:51:00 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (!(*s1++ == *s2++))
			return ((unsigned char)(*(s1 - 1)) - (unsigned char)(*(s2 - 1)));
		if (*(s1 - 1) == 0 || *(s2 - 1) == 0)
			return ((unsigned char)(*(s1 - 1)) - (unsigned char)(*(s2 - 1)));
	}
	return (0);
}
