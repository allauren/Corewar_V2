/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:53:17 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/18 02:55:54 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_wchar_byte(wchar_t c)
{
	unsigned int	len;
	unsigned int	tmp;

	len = 0;
	tmp = 1;
	while (tmp <= (unsigned int)c)
	{
		tmp <<= 1;
		len++;
	}
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	else if (len <= 21)
		return (4);
	else
		return (-1);
}
