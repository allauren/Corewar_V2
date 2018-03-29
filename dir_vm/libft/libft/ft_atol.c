/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:06:48 by gsmith            #+#    #+#             */
/*   Updated: 2018/01/14 14:06:50 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *str)
{
	long	i;
	long	jack;
	int		neg;

	i = 0;
	jack = 0;
	neg = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
	(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		jack = jack * 10;
		jack = str[i] - '0' + jack;
		i++;
	}
	return ((jack * neg));
}
