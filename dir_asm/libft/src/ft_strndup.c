/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:40:54 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:40:56 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	int		len;

	len = ft_strlen((char*)s1) >= n ? n : ft_strlen((char*)s1);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(dest, s1, n));
}
