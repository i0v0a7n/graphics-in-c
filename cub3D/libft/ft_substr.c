/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 00:54:33 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/09 21:24:07 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*retstr;
	size_t	i;

	i = 0;
	retstr = malloc(len + 1);
	if (retstr == 0 || s == 0)
		return (0);
	if (start < ft_strlen(s))
		while (s[start] != 0 && len--)
			retstr[i++] = s[start++];
	retstr[i] = 0;
	return (retstr);
}
