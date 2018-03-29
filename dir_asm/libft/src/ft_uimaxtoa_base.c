/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:55:55 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/17 21:49:10 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uimaxtoa_base(uintmax_t n, int base)
{
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen_uimax_base(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len--] = '\0';
	while (n > 0)
	{
		if (n % base < 10)
			str[len--] = n % base + '0';
		else
			str[len--] = n % base - 10 + 'a';
		n /= base;
	}
	return (str);
}
