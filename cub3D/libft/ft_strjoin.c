/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:43:52 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/09 21:31:31 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retstr;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	retstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (retstr == 0)
		return (0);
	while (*s1)
		retstr[i++] = *s1++;
	while (*s2)
		retstr[i++] = *s2++;
	retstr[i] = 0;
	return (retstr);
}
