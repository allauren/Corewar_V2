/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:39:55 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:39:56 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*str;

	index = -1;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++index])
		str[index] = f(s[index]);
	return (str);
}
