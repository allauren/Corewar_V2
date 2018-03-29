/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:08:43 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/14 10:39:05 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	if (len >= size)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (i + len + 1) < size)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = 0;
	return (ft_strlen(src) + len);
}
