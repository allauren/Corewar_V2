/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:56:01 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/18 01:23:44 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	len;
	int		bytes;

	len = 0;
	bytes = 0;
	while (*wstr)
	{
		if ((bytes = ft_wchar_byte(*wstr)) == -1)
			return (0);
		len += (size_t)bytes;
		wstr++;
	}
	return (len);
}
