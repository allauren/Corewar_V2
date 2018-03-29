/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itowchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:10:24 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/02 16:01:42 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_itowchar(unsigned int val, char **wch)
{
	int				nbc;
	int				i;
	unsigned int	tmp;

	nbc = 0;
	tmp = 128 + 128 * (MB_CUR_MAX == 1);
	while (nbc++ < MB_CUR_MAX && val >= tmp)
		tmp = (tmp << (4 + (nbc != 1)));
	if (nbc > MB_CUR_MAX || val >= 0x10ffff || (val > 0xd7ff && val < 0xe000))
		return (0);
	if (!(wch) || !(*wch = ft_strnew(nbc)))
		return (0);
	if (nbc > 1)
	{
		i = nbc - 1;
		while (i > 0)
		{
			(*wch)[i--] = ((val & 0x3F) | 0x80);
			val = val >> 6;
		}
		(*wch)[i] = (val | ((0xF00 >> nbc) & 0xF0));
	}
	else
		(*wch)[0] = val;
	return (nbc);
}
