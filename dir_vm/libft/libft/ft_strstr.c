/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:04:52 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/12 14:20:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;
	size_t	i;

	n = ft_strlen(needle);
	if (!n)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (!ft_strncmp(haystack + i, needle, n))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
