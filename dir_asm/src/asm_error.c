/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 08:44:42 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 16:27:47 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_error_1(t_asm *data)
{
	ft_bzero(data->file, sizeof(char) * (FILE_MAX_SIZE + 16));
	get_next_line(data->fd, NULL);
	close(data->fd);
	free(data->file);
	free(data->line);
	free(data);
	ft_perror("Error");
}

void		asm_error_2(t_asm *data)
{
	int		error;

	ft_bzero(data->file, sizeof(char) * (FILE_MAX_SIZE + 16));
	get_next_line(data->fd, NULL);
	close(data->fd);
	free(data->file);
	free(data->line);
	error = data->error;
	free(data);
	if (ft_dprintf(2, "Error: Syntax error (line %d)\n", error) < 0)
		ft_perror("Error");
	exit(EXIT_FAILURE);
}

void		asm_error_3(char *file)
{
	ft_bzero(file, sizeof(char) * (FILE_MAX_SIZE + 16));
	free(file);
	ft_perror("Error");
}

void		asm_error_4(int fd, char *file, char *name_cor)
{
	ft_bzero(file, sizeof(char) * (FILE_MAX_SIZE + 16));
	if (fd >= 0)
		close(fd);
	free(file);
	free(name_cor);
	ft_perror("Error");
}

void		asm_error_5(t_asm *data, int check)
{
	ft_bzero(data->file, sizeof(char) * (FILE_MAX_SIZE + 16));
	get_next_line(data->fd, NULL);
	close(data->fd);
	free(data->file);
	free(data->line);
	free(data);
	if (!check)
	{
		if (ft_putstr_fd("Error: Name too long\n", 2) < 0)
			ft_perror("Error");
	}
	else
	{
		if (ft_putstr_fd("Error: Comment too long\n", 2) < 0)
			ft_perror("Error");
	}
	exit(EXIT_FAILURE);
}
