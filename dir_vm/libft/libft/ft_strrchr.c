/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:52:35 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/12 14:17:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last_pos;
	t_bool	found;
	char	casted_c;

	i = 0;
	found = FALSE;
	casted_c = (char)c;
	while (s[i])
	{
		if (s[i] == casted_c)
		{
			last_pos = i;
			found = TRUE;
		}
		i++;
	}
	if (s[i] == casted_c)
		return ((char *)s + i);
	if (found)
		return ((char *)s + last_pos);
	return (NULL);
}
