/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 09:47:48 by allauren          #+#    #+#             */
/*   Updated: 2018/03/11 00:27:05 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_fill_memory(unsigned char *memory, unsigned char *buf, \
		int start, int stop)
{
	int		i;
	int		z;

	i = start;
	z = -1;
	while (++z < stop)
		memory[i++] = buf[z];
}
