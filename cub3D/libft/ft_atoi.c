/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:55:45 by sfrey             #+#    #+#             */
/*   Updated: 2020/11/09 20:40:45 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	buf;
	int	neg;

	neg = 1;
	buf = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'\
		|| *str == '\v' || *str == '\f' || *str == '\n')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		buf = (buf * 10) + (*str - '0');
		str++;
	}
	return (buf * neg);
}
