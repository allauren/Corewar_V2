/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:22:56 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/13 20:01:09 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char			*ft_strtrim(char const *s)
{
	char	*res;
	size_t	pref;
	size_t	suff;
	size_t	i;

	if (!s)
		return (NULL);
	pref = 0;
	while (s[pref] && (s[pref] == ' ' || s[pref] == '\n' || s[pref] == '\t'))
		pref++;
	suff = ft_strlen(s) - 1;
	while (suff > 0 && (s[suff] == ' ' || s[suff] == '\n' || s[suff] == '\t'))
		suff--;
	if (suff < pref)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (suff - pref + 2))))
		return (NULL);
	i = 0;
	while ((i + pref) < (suff + 1))
	{
		res[i] = s[pref + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
