/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:50:01 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/25 23:46:40 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_op_process(t_asm *data, char *tmp)
{
	int			index;

	index = 0;
	while (ft_strchr(LABEL_CHARS, tmp[index]) && tmp[index])
		index++;
	if (tmp[index] == LABEL_CHAR)
	{
		asm_add_lab(data, ft_strndup(tmp, index));
		tmp += index + 1;
		asm_op_process(data, ft_spacejump(tmp));
	}
	else if (ft_isalpha(*tmp))
		asm_op_line(data, tmp);
	else if (*tmp != '\0')
		asm_error_7(data);
	if (data->size > FILE_MAX_SIZE)
		asm_error_8(data);
}
