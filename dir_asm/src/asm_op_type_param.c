/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_type_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:17:32 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/25 23:46:32 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_check_fill(t_asm *data, char *tmp, int size)
{
	int		val;
	int		count;

	val = ft_atoi_sec(tmp);
	count = 0;
	while (tmp[count] && ft_isdigit(tmp[count]))
		count++;
	if (count > 2 && val == -1)
		asm_error_10(data, 0);
	if (size == 2 && (val > SHRT_MAX || val < SHRT_MIN))
		asm_error_10(data, 1);
}

static int	asm_op_reg(t_asm *data, char *tmp)
{
	int		reg;

	reg = ft_atoi_sec(++tmp);
	if (reg <= 0 || reg > REG_NUMBER)
		asm_error_12(data);
	else
		asm_put_hexa(data->file + data->size, reg, 1);
	data->size++;
	while (ft_isdigit(*tmp))
		tmp++;
	if (!ft_isspace(*tmp) && *tmp && *tmp != ',')
		asm_error_7(data);
	return (1);
}

static int	asm_op_dir(t_asm *data, char *tmp, int ft)
{
	int		val;

	if (*(++tmp) == ':')
		asm_add_lab_pos(data, tmp, data->size - data->pc + 1, ft);
	else
	{
		if ((*tmp == '-' && !ft_isdigit(*(tmp + 1))) ||
		(!ft_isdigit(*tmp) && *tmp != '-'))
			asm_error_7(data);
		asm_check_fill(data, tmp, ft);
		val = ft_atoi(tmp);
		if (val >= 0)
			asm_put_hexa(data->file + data->size, val, ft);
		else
			asm_put_hexa(data->file + data->size, (ft == 2 ? 0xFFFF :
			0xFFFFFFFF) + val + 1, ft);
		if (*tmp == '-')
			tmp++;
		while (ft_isdigit(*tmp))
			tmp++;
		if (!ft_isspace(*tmp) && *tmp && *tmp != ',')
			asm_error_7(data);
	}
	data->size += ft;
	return (2);
}

static int	asm_op_ind(t_asm *data, char *tmp)
{
	int		val;

	if (*tmp == ':')
		asm_add_lab_pos(data, tmp, data->size - data->pc + 1, 2);
	else
	{
		if ((*tmp == '-' && !ft_isdigit(*(tmp + 1))) ||
		(!ft_isdigit(*tmp) && *tmp != '-'))
			asm_error_7(data);
		asm_check_fill(data, tmp, 2);
		val = ft_atoi(tmp);
		if (val >= 0)
			asm_put_hexa(data->file + data->size, val, 2);
		else
			asm_put_hexa(data->file + data->size, 0xFFFF + val + 1, 2);
		if (*tmp == '-')
			tmp++;
		while (ft_isdigit(*tmp))
			tmp++;
		if (!ft_isspace(*tmp) && *tmp && *tmp != ',')
			asm_error_7(data);
	}
	data->size += 2;
	return (3);
}

int			asm_op_type_param(t_asm *data, int idx_param, char *tmp)
{
	int		type_val;
	int		ret;

	ret = 0;
	type_val = g_op_tab[data->idx].param_types[idx_param];
	if (*tmp == 'r' && (type_val & T_REG) > 0)
		ret = asm_op_reg(data, tmp);
	else if (*tmp == '%' && (type_val & T_DIR) > 0)
		ret = asm_op_dir(data, tmp, !g_op_tab[data->idx].has_idx ? 4 : 2);
	else if ((*tmp == LABEL_CHAR || *tmp == '-' || ft_isdigit(*tmp)) &&
	(type_val & T_IND) > 0)
		ret = asm_op_ind(data, tmp);
	else
		asm_error_7(data);
	return (ret << (2 + (2 - idx_param) * 2));
}
