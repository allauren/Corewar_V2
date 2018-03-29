/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:38:50 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 20:57:34 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lftoa(double n)
{
	int			length;
	int			idx;
	int			check;
	char		*str;

	length = ft_lflen(n);
	if (!(str = ft_strnew(length)))
		return (NULL);
	check = ft_itoa_dst(str, (intmax_t)n);
	n *= n < 0 ? -1 : 1;
	n = n - (intmax_t)n;
	idx = 0;
	while (idx < 6)
	{
		n = (n * 10) + 0.0000001;
		idx++;
	}
	str[check++] = '.';
	ft_itoa_dst(str + check, (intmax_t)n);
	return (str);
}
