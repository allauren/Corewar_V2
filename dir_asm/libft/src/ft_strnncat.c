/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:40:12 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 01:29:27 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	check;

	index = -1;
	check = ft_strlen(s1);
	while (++index < n)
		s1[check + index] = s2[index];
	return (s1);
}
