/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:05:17 by gsmith            #+#    #+#             */
/*   Updated: 2018/01/14 13:41:59 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	size_t	i;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = malloc(content_size)))
		{
			free(res);
			return (NULL);
		}
		i = -1;
		while (++i < content_size)
			((unsigned char *)(res->content))[i] =
				((unsigned char*)content)[i];
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
