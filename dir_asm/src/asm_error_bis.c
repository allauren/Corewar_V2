/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:51:23 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/25 17:17:43 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_error_6(t_asm *data)
{
	int	error;

	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	error = data->error;
	free(data);
	if (ft_putstr_fd("Error: Label used doesn't exists\n", 2) < 0)
		ft_perror("Error");
	exit(EXIT_FAILURE);
}

void	asm_error_7(t_asm *data)
{
	int	error;

	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	error = data->error;
	free(data);
	if (ft_dprintf(2, "Error: Syntax error (line %d)\n", error) < 0)
		ft_perror("Error");
	exit(EXIT_FAILURE);
}

void	asm_error_8(t_asm *data)
{
	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	free(data);
	if (ft_putstr_fd("Error: Champ too long\n", 2) < 0)
		ft_perror("Error");
	exit(EXIT_FAILURE);
}

void	asm_error_9(t_asm *data)
{
	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	free(data);
	ft_perror("Error");
}

void	asm_error_10(t_asm *data, int check)
{
	int	error;

	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	error = data->error;
	free(data);
	if (!check)
	{
		if (ft_dprintf(2, "Error: Value over int (line %d)\n", error) < 0)
			ft_perror("Error");
	}
	else
	{
		if (ft_dprintf(2, "Error: Value over short (line %d)\n", error) < 0)
			ft_perror("Error");
	}
	exit(EXIT_FAILURE);
}
