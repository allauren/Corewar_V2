/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:19:42 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 15:03:13 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "memory.h"

void		ft_process(t_proc **pc, t_memory *m, t_param *p)
{
	t_proc	*tmp;
	int		i;

	i = 0;
	(void)m;
	*pc = NULL;
	while (p->nchamp[i].fd)
	{
		if (!(tmp = ft_memalloc(sizeof(t_proc))))
			ft_perror("malloc error");
		tmp->reg[0] = p->nchamp[i].num_player;
		tmp->pc = (MEM_SIZE / p->nb_champ) * i++;
		if (*pc)
			tmp->next = *pc;
		*pc = tmp;
	}
}
