/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:53:25 by sfrey             #+#    #+#             */
/*   Updated: 2021/04/29 17:44:23 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_act2(char *ret, int n, int i)
{
	ret[i--] = 0;
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n)
	{
		ret[i--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		copy;

	if (n < 0)
		i = 2;
	else
		i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	copy = n;
	while (copy)
	{
		copy /= 10;
		i++;
	}
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	return (ft_act2(ret, n, i));
}
