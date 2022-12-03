/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 02:01:33 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/29 17:40:41 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_subsize(const char *str, size_t pos, char c)
{
	size_t	offset;

	offset = 0;
	while (str[pos] != c && str[pos] != '\0')
	{
		pos++;
		offset++;
	}
	return (offset);
}

static size_t	ft_stramount(const char *str, char c)
{
	size_t	amount;
	size_t	i;

	if (str[0] == 0)
		return (0);
	if (str[0] == c)
		amount = 0;
	else
		amount = 1;
	i = 1;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i - 1] == c)
			amount++;
		i++;
	}
	return (amount);
}

static void	ft_budgetstr(char *str, char const *s, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**super;
	size_t	amount;
	size_t	pos;
	size_t	i;

	pos = 0;
	if (!s)
		return (0);
	amount = ft_stramount(s, c);
	super = (char **)malloc((sizeof(char *) * (amount + 1)));
	i = 0;
	while (i < amount)
	{
		while (s[pos] == c)
			pos++;
		super[i] = malloc(ft_subsize(s, pos, c) + 1);
		ft_budgetstr(super[i++], s, pos, ft_subsize(s, pos, c));
		pos += ft_subsize(s, pos, c);
	}
	super[amount] = 0;
	return (super);
}
