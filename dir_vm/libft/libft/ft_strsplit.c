/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:29:24 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/12 14:36:48 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	nb_str(char const *s, char c)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		nb += s[i] != 0;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static size_t	extract_str(char **dst, const char *src, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	if (!(*dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		(*dst)[i] = src[i];
		i++;
	}
	(*dst)[i] = 0;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	nb;
	size_t	nb_s;

	if (!s)
		return (NULL);
	nb_s = nb_str(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (nb_s + 1))))
		return (NULL);
	res[nb_s] = 0;
	i = 0;
	nb = 0;
	while (nb < nb_s)
	{
		while (s[i] == c)
			i++;
		i += extract_str(res + nb, s + i, c);
		nb++;
	}
	return (res);
}
