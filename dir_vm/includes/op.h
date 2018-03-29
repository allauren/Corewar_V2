/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 10:37:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/25 16:34:25 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# include "memory.h"
# include "process.h"
# include "cycles.h"

typedef struct	s_op
{
	char				*name;
	int					nb_arg;
	int					args[3];
	unsigned char		opc;
	unsigned int		sleep;
	char				*desc;
	t_bool				carry;
	t_bool				size_dir;
	void				(*fun)(t_memory *, t_proc *, t_proc **, t_timer *);
}				t_op;

extern t_op		g_op_tab[17];

void			op_live(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_ld(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_st(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_add(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_sub(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_and(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_or(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_xor(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_zjmp(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_ldi(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_sti(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_fork(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_lld(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_lldi(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_lfork(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);
void			op_aff(t_memory *mem, t_proc *proc, t_proc **lst_proc,
		t_timer *timer);

#endif
