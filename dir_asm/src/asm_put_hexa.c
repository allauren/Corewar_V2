/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_put_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:21:50 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 16:15:39 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_put_hexa(char *str, unsigned int hexa, int size)
{
	while (size)
	{
		str[size - 1] = hexa % 256;
		hexa /= 256;
		size--;
	}
}
