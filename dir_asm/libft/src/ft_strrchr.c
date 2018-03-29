/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:41:53 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:41:54 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen((char*)s);
	while (s[index] != (char)c && index >= 0)
		index--;
	if (s[index] != (char)c)
		return (NULL);
	return ((char*)s + index);
}
