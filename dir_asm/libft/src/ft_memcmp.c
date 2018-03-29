/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:31:42 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:31:43 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (index < n && ((char*)s1)[index] == ((char*)s2)[index])
		index++;
	if (index == n)
		index--;
	return (((unsigned char*)s1)[index] - ((unsigned char*)s2)[index]);
}
