/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:54:27 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/24 13:08:58 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_itoa_b(unsigned long long nb, char *base)
{
	char				*res;
	int					b_size;
	unsigned long long	div;
	int					len;

	b_size = ft_strlen(base);
	if (b_size < 2)
		return (NULL);
	div = nb;
	len = (div == 0);
	while (div > 0)
	{
		div = div / b_size;
		len++;
	}
	res = ft_strnew(len);
	res[len--] = '\0';
	div = nb;
	while (len >= 0)
	{
		res[len--] = base[div % b_size];
		div = div / b_size;
	}
	return (res);
}
