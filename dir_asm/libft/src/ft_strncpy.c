/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:40:35 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:40:36 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = -1;
	while (src[++index] && index < n)
		dst[index] = src[index];
	index--;
	while (++index < n)
		dst[index] = '\0';
	return (dst);
}
