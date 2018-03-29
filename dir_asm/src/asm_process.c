/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 01:04:46 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/14 07:03:31 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_process(int fd, char **file)
{
	t_asm	*data;
	int		size;

	if (!(data = (t_asm*)ft_memalloc(sizeof(t_asm))))
	{
		close(fd);
		ft_perror("Error");
	}
	data->fd = fd;
	if (!(data->file = ft_strnew(FILE_MAX_SIZE + 16)))
		asm_error_1(data);
	asm_put_hexa(data->file, COREWAR_EXEC_MAGIC, 4);
	data->size += 4;
	asm_get_name(data);
	data->size += 8;
	asm_get_comment(data);
	data->size += 4;
	asm_get_op(data);
	asm_put_hexa(data->file + 4 + PROG_NAME_LENGTH, data->size -
	HEADER_LENGTH, 8);
	size = data->size;
	*file = data->file;
	get_next_line(fd, NULL);
	free(data);
	return (size);
}
