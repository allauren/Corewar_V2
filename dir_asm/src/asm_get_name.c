/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:12:58 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/25 15:55:02 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_check_name_length(t_asm *data, char *tmp, int index)
{
	if (index == PROG_NAME_LENGTH && *tmp != '"')
		asm_error_5(data, 0);
	while (index < PROG_NAME_LENGTH)
	{
		data->file[data->size] = '\0';
		data->size++;
		index++;
	}
}

static void	asm_parse_name(t_asm *data, char *tmp)
{
	int		index;

	index = 0;
	tmp += ft_strlen(NAME_CMD_STRING);
	tmp = ft_spacejump(tmp);
	if (tmp[0] != '"')
		asm_error_2(data);
	tmp++;
	while (*tmp && *tmp != '"' && index < PROG_NAME_LENGTH)
	{
		data->file[data->size] = *tmp;
		tmp++;
		index++;
		data->size++;
	}
	asm_check_name_length(data, tmp, index);
	if (*tmp != '"')
		asm_error_2(data);
	tmp++;
	tmp = ft_spacejump(tmp);
	if (tmp[0] && tmp[0] != COMMENT_CHAR)
		asm_error_2(data);
}

void		asm_get_name(t_asm *data)
{
	char	*tmp;
	int		ret;

	while ((ret = get_next_line(data->fd, &(data->line))) > 0)
	{
		data->error++;
		tmp = ft_spacejump(data->line);
		if (!ft_strncmp(tmp, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			break ;
		else if (tmp[0] != COMMENT_CHAR && tmp[0])
			asm_error_2(data);
		else
			ft_strdel(&(data->line));
	}
	if (ret < 0)
		asm_error_1(data);
	if (ret == 0)
		asm_error_2(data);
	asm_parse_name(data, tmp);
	ft_strdel(&(data->line));
}
