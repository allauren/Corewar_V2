/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:48:56 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/12 14:12:22 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	if (n)
	{
		sc1 = (unsigned char *)s1;
		sc2 = (unsigned char *)s2;
		i = 0;
		while (sc1[i] == sc2[i] && (i + 1) < n)
			i++;
		return ((int)(sc1[i] - sc2[i]));
	}
	return (0);
}
