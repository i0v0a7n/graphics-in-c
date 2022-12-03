/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:34:37 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/29 17:32:36 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrchr(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
		if (set[i++] == s1)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*retstr;
	size_t	end;
	size_t	start;
	size_t	i;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	end = ft_strlen(s1);
	start = 0;
	while (ft_istrchr(s1[start], set) && s1[start])
		start++;
	while (ft_istrchr(s1[end - 1], set) && end > start)
		end--;
	retstr = malloc(end - start + 1);
	if (retstr == 0)
		return (0);
	while (start < end)
		retstr[i++] = s1[start++];
	retstr[i] = '\0';
	return (retstr);
}
