/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:46:47 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 21:17:58 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lfstrlen(char *str)
{
	int	count;

	count = 1;
	while (str[count] && str[count] != '.')
		count++;
	return (count);
}
