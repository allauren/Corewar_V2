/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:01:21 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/13 20:24:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_bool	init_itoa(int n, char **res)
{
	t_bool	neg;
	int		len;
	long	div;

	if (n < 0)
	{
		len = 2;
		neg = TRUE;
	}
	else
	{
		len = 1;
		neg = FALSE;
	}
	div = 10;
	while (n / div != 0)
	{
		div = div * 10;
		len++;
	}
	if (!(*res = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	return (neg);
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*res;
	int		i;
	long	div;

	if ((neg = init_itoa(n, &res)) == -1)
		return (NULL);
	i = 0;
	if (neg)
		res[i++] = '-';
	div = 10;
	while (n / div != 0)
		div = div * 10;
	div = div / 10;
	while (div > 0)
	{
		res[i++] = (-2 * neg + 1) * (n / div) + '0';
		n = (n % div);
		div = div / 10;
	}
	res[i] = 0;
	return (res);
}
