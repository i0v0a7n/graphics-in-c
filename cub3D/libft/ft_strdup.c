/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:34:41 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/09 19:56:46 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*p;
	size_t			len;
	size_t			i;

	i = 0;
	len = ft_strlen(s1);
	if (len > 0)
	{
		p = (char *)malloc((len + 1) * sizeof(char));
		if (p == 0)
			return (0);
		while (i < len)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = 0;
		return (p);
	}
	else
		p = malloc(1);
	if (p == 0)
		return (0);
	*p = 0;
	return (p);
}
