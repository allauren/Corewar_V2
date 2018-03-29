/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 07:56:52 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 18:35:06 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lflen(double n)
{
	size_t	ret;
	int		n_int;

	ret = 0;
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	n_int = (int)n;
	while (n_int)
	{
		n_int /= 10;
		ret++;
	}
	ret += 7;
	return (ret);
}
