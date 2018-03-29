/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 06:05:24 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 19:33:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_replace_labs(t_asm *data)
{
	t_labs		*tmp;
	t_lab_pos	*tmp_pos;
	int			neg_val;

	tmp = data->labs;
	while (tmp)
	{
		tmp_pos = tmp->pos;
		while (tmp_pos)
		{
			if (tmp->index >= tmp_pos->index)
				asm_put_hexa(data->file + tmp_pos->index, tmp->index -
				tmp_pos->index + tmp_pos->pc, tmp_pos->size);
			else
			{
				neg_val = (tmp_pos->size == 2) ? 0xFFFF : 0xFFFFFFFF;
				asm_put_hexa(data->file + tmp_pos->index, neg_val -
				(tmp_pos->index - tmp->index - 1 - tmp_pos->pc),
				tmp_pos->size);
			}
			tmp_pos = tmp_pos->next;
		}
		tmp = tmp->next;
	}
}

static void		asm_check_labs(t_asm *data)
{
	t_labs		*tmp;

	tmp = data->labs;
	while (tmp)
	{
		if (!tmp->define)
			asm_error_6(data);
		tmp = tmp->next;
	}
}

void			asm_get_op(t_asm *data)
{
	char		*tmp;
	int			ret;

	while ((ret = get_next_line(data->fd, &(data->line))) > 0)
	{
		data->error++;
		tmp = ft_spacejump(data->line);
		if (tmp[0] != COMMENT_CHAR && tmp[0])
			asm_op_process(data, tmp);
		ft_strdel(&(data->line));
	}
	if (ret < 0)
		asm_error_1(data);
	asm_check_labs(data);
	asm_replace_labs(data);
	asm_labs_del(data->labs);
}
