/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:40:12 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/19 17:45:01 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	check;

	index = 0;
	check = ft_strlen(s1);
	while (s2[index] != '\0' && index < n)
	{
		s1[check + index] = s2[index];
		index++;
	}
	s1[check + index] = '\0';
	return (s1);
}
