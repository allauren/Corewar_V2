/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/19 15:35:53 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "vm.h"

t_ui			read_mem(t_memory *mem, int ind, int size)
{
	t_ui	res;

	res = 0;
	while (size > 0)
	{
		res = (res << 8) + (t_ui)((mem->memory)[ind % MEM_SIZE]);
		(ind)++;
		size--;
	}
	return (res);
}

void			write_mem(t_memory *mem, t_ui ind, t_ui val)
{
	t_ui	i;
	t_uc	b;

	i = -1;
	while (++i < 4)
	{
		b = (t_uc)((val >> ((3 - i) * 8)) & 0xFF);
		(mem->memory)[(ind + i) % MEM_SIZE] = b;
	}
}

t_ui			ind_sum_ldi(t_ui ocp, t_memory *mem, t_proc *proc, int *offset)
{
	t_ui		rg;
	t_ui		ind;

	if (ARG(ocp, 3) == A_REG)
	{
		rg = get_dest_idx(mem, proc, A_REG, offset);
		ind = rg ? (proc->reg)[rg - 1] : 0;
	}
	else
	{
		ind = read_mem(mem, pc_offset(proc->pc, *offset), 2);
		*offset += 2;
		ind = (ARG(ocp, 3) == A_IND) ? read_mem(mem, ind, 4) : ind;
	}
	if (ARG(ocp, 2) == A_REG)
	{
		rg = get_dest_idx(mem, proc, A_REG, offset);
		ind += !proc->err ? (proc->reg)[rg - 1] : 0;
	}
	else
	{
		ind += read_mem(mem, pc_offset(proc->pc, *offset), 2);
		*offset += 2;
	}
	return (ind);
}

t_ui			ind_sum_sti(t_ui ocp, t_memory *mem, t_proc *proc, int *offset)
{
	t_ui		rg;
	t_ui		ind;

	if (ARG(ocp, 2) == A_REG)
	{
		rg = get_dest_idx(mem, proc, A_REG, offset);
		ind = rg ? (proc->reg)[rg - 1] : 0;
	}
	else
	{
		ind = read_mem(mem, pc_offset(proc->pc, *offset), 2);
		*offset += 2;
		ind = (ARG(ocp, 2) == A_IND) ? read_mem(mem, ind, 4) : ind;
	}
	if (ARG(ocp, 1) == A_REG)
	{
		rg = get_dest_idx(mem, proc, A_REG, offset);
		ind += !proc->err ? (proc->reg)[rg - 1] : 0;
	}
	else
	{
		ind += read_mem(mem, pc_offset(proc->pc, *offset), 2);
		*offset += 2;
	}
	return (ind);
}

t_ui			pc_offset(t_ui pc, int offset)
{
	if (offset < 0 && (-1 * offset) > MEM_SIZE)
		offset = -1 * ((-1 * offset) % MEM_SIZE);
	if (offset < 0 && pc < (t_ui)(-1 * offset))
		pc += MEM_SIZE + offset;
	else
		pc += offset;
	if (pc > MEM_SIZE)
		pc = pc % MEM_SIZE;
	return (pc);
}
