/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 15:47:58 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"
#include "memory.h"
#include "process.h"
#include "cycles.h"
#include "op_utils.h"
#include <stdlib.h>

void			vm_run(t_memory *mem, t_proc **proc, t_timer *timer)
{
	t_proc		*cursor;
	int			i;
	t_ui		opc;

	cursor = *proc;
	while (cursor)
	{
		opc = (mem->memory)[cursor->pc];
		i = 0;
		while (i < 16 && g_op_tab[i].opc != opc)
			i++;
		if (i < 16)
		{
			cursor->sleep++;
			if (cursor->sleep >= g_op_tab[i].sleep && !(cursor->sleep = 0))
				g_op_tab[i].fun(mem, cursor, proc, timer);
		}
		else
		{
			cursor->sleep = 0;
			cursor->pc = pc_offset(cursor->pc, 1);
		}
		cursor = cursor->next;
	}
}

void			vm_introduce(t_chmp chmp[4], int nb_champ)
{
	int		i;

	i = -1;
	ft_putendl("Introducing contestants...");
	while (++i < nb_champ)
		ft_printf("* Player %u, weighing %d bytes, \"%s\" (\"%s\") !\n",
			chmp[i].num_player, chmp[i].head.prog_size,
				chmp[i].head.prog_name, chmp[i].head.comment);
}

void			vm_winner(t_memory *m, t_bool show_winner)
{
	t_chmp		*player;

	player = m->last_live;
	if (show_winner)
		ft_printf("\nContestant %u, \"%s\", has won !\n",
				player->num_player, player->head.prog_name);
	else
		print_memory(m->memory, MEM_SIZE);
}

void			vm_periodic_print(t_memory *m, t_proc **proc)
{
	char	input;
	int		r;

	print_memory(m->memory, MEM_SIZE);
	while ((r = read(0, &input, 1)) > -1)
	{
		if (input == 10)
			break ;
		else if (input == 'q')
		{
			while (*proc)
				proc_kill(proc);
			exit(0);
		}
	}
}

int				main(int argc, char *argv[])
{
	t_param		p;
	t_memory	m;
	t_timer		t;
	t_proc		*pc;

	if (argc == 1)
		corewar_usage();
	ft_bzero(&p, sizeof(t_param));
	ft_bzero(&m, sizeof(t_memory));
	ft_parse_options(argc, argv, &p, &m);
	t = cycle_init();
	ft_process(&pc, &m, &p);
	vm_introduce(m.chp, m.nb_champ);
	while ((!p.dump || t.cycle <= p.dmp) && pc)
	{
		vm_run(&m, &pc, &t);
		cycle_count(&t, &pc);
		if (p.periodic && !(t.cycle % p.periodic))
			vm_periodic_print(&m, &pc);
	}
	vm_winner(&m, !(p.dump) || t.cycle < p.dmp);
	while (pc)
		proc_kill(&pc);
	return (0);
}
