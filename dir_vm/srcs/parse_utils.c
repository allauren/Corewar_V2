/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:14:57 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 15:05:17 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void		ft_isactive(int i, int *j, int value)
{
	if (i)
		ft_perror("invalid parameter");
	else
		*j = value;
}
