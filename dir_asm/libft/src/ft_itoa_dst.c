/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_dst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:28:06 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 20:16:28 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_itoa_dst(char *dst, intmax_t n)
{
	intmax_t	tmp_n;
	int			length;
	int			sign;

	length = 1;
	sign = 1;
	tmp_n = n;
	while (tmp_n /= 10)
		length++;
	if (n < 0)
	{
		sign = -1;
		length++;
	}
	while (length--)
	{
		dst[length] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		dst[0] = '-';
	return (ft_strlen(dst));
}
