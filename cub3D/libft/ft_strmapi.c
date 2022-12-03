/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:29:16 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/09 21:35:00 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strsucker;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	strsucker = malloc(ft_strlen(s) + 1);
	if (strsucker == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		strsucker[i] = f(i, s[i]);
		i++;
	}
	strsucker[i] = '\0';
	return (strsucker);
}
