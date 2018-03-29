/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 01:28:34 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/08 02:50:11 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strappend(char **s1, char **s2, char c)
{
	char	*ret;

	ret = ft_strjoin(*s1, *s2);
	if (c == 'F' || c == 'B')
		ft_strdel(s1);
	if (c == 'S' || c == 'B')
		ft_strdel(s2);
	return (ret);
}
