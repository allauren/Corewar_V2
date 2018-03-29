/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:16:12 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:34:49 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin_free(void *s1, size_t len1, void *s2, size_t len2)
{
	char	*ret;

	if (!(ret = (char*)ft_memalloc(sizeof(char) * (len1 + len2))))
		return (NULL);
	if (s1)
		ft_memcpy((void*)ret, s1, len1);
	if (s2)
		ft_memcpy((void*)ret + len1, s2, len2);
	free(s1);
	free(s2);
	return ((void*)ret);
}
