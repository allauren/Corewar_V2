/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:34:56 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:34:57 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_tmp;
	unsigned char	*dst_tmp;

	src_tmp = (unsigned char*)src;
	dst_tmp = (unsigned char*)dst;
	if (!len)
		return (dst);
	if (dst > src)
	{
		while (len--)
			dst_tmp[len] = src_tmp[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
