/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:26:11 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/25 16:04:24 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_check_comment_length(t_asm *data, char *tmp, int index)
{
	if (index == COMMENT_LENGTH && *tmp != '"')
		asm_error_5(data, 1);
	while (index < COMMENT_LENGTH)
	{
		data->file[data->size] = '\0';
		data->size++;
		index++;
	}
}

static void	asm_parse_comment(t_asm *data, char *tmp)
{
	int		index;

	index = 0;
	tmp += ft_strlen(COMMENT_CMD_STRING);
	tmp = ft_spacejump(tmp);
	if (tmp[0] != '"')
		asm_error_2(data);
	tmp++;
	while (*tmp && *tmp != '"' && index < COMMENT_LENGTH)
	{
		data->file[data->size] = *tmp;
		tmp++;
		index++;
		data->size++;
	}
	asm_check_comment_length(data, tmp, index);
	if (*tmp != '"')
		asm_error_2(data);
	tmp++;
	tmp = ft_spacejump(tmp);
	if (tmp[0] && tmp[0] != COMMENT_CHAR)
		asm_error_2(data);
}

void		asm_get_comment(t_asm *data)
{
	char	*tmp;
	int		ret;

	while ((ret = get_next_line(data->fd, &(data->line))) > 0)
	{
		data->error++;
		tmp = ft_spacejump(data->line);
		if (!ft_strncmp(tmp, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
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
	asm_parse_comment(data, tmp);
	ft_strdel(&(data->line));
}
