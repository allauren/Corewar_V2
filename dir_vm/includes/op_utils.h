/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:02:38 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/10 15:47:09 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_UTILS_H
# define OP_UTILS_H

# include "memory.h"
# include "process.h"

# define ARG(opc, pos) ((opc & (3 << (pos * 2))) >> (pos * 2))
# define A_REG 1
# define A_DIR 2
# define A_IND 3

t_ui		read_mem(t_memory *mem, int ind, int size);
void		write_mem(t_memory *mem, t_ui ind, t_ui val);
t_ui		ind_sum_ldi(t_ui ocp, t_memory *mem, t_proc *proc, int *offset);
t_ui		ind_sum_sti(t_ui ocp, t_memory *mem, t_proc *proc, int *offset);
t_ui		get_val(t_memory *mem, t_proc *proc, t_ui typ, int *offset);
t_ui		get_val_idx(t_memory *mem, t_proc *proc, t_ui typ, int *offset);
t_ui		get_dest(t_memory *mem, t_proc *proc, t_ui typ, int *offset);
t_ui		get_dest_idx(t_memory *mem, t_proc *proc, t_ui typ, int *offset);
t_ui		restrict_ind(t_ui index);
t_ui		pc_offset(t_ui pc, int offset);

#endif
