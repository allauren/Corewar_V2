/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:08:30 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:32:33 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *s, size_t n)
{
	char	*ret;

	if (!(ret = ft_strnew(n)))
		return (NULL);
	ret = (char*)ft_memcpy((void*)ret, s, n);
	return ((void*)ret);
}
