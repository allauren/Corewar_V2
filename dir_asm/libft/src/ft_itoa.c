/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:28:06 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 18:05:28 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		length;
	int		tmp_n;
	int		sign;
	char	*str;

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
	if (!(str = ft_strnew(length)))
		return (NULL);
	while (length--)
	{
		str[length] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
