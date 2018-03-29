/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend_sec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:20:56 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/11 19:21:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strappend_sec(char **s1, char **s2, char c)
{
	char	*ret;

	if (s1 && *s1 && s2 && *s2)
		ret = ft_strjoin(*s1, *s2);
	else if (s1 && *s1)
		ret = ft_strdup(*s1);
	else if (s2 && *s2)
		ret = ft_strdup(*s2);
	else
		ret = ft_strdup("");
	if (c == 'F' || c == 'B')
		ft_strdel(s1);
	if (c == 'S' || c == 'B')
		ft_strdel(s2);
	return (ret);
}
