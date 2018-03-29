/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 09:01:58 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 15:05:11 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_isolatebufc(t_uc *buf, char *cpy, int start, int end)
{
	int		i;

	i = 0;
	while (start < end)
	{
		cpy[i++] = HEX[buf[start] / 16];
		cpy[i++] = HEX[buf[start] % 16];
		start++;
	}
}

void	ft_check_magic(t_memory *m, t_param *p, int i)
{
	ft_isolatebufc(p->buf, m->magic, 0, 4);
	if (COREWAR_MAGIC != (p->nchamp[i].head.magic = ft_atoi_base(m->magic, 16)))
		ft_perror("invalid magic");
}

void	ft_check_prog_size(t_memory *m, t_param *p, int i)
{
	ft_isolatebufc(p->buf, m->size, 132, 140);
	p->nchamp[i].head.prog_size = ft_atoi_base(m->size, 16);
}
