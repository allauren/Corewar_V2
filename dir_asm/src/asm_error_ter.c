/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_ter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:53:15 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 16:47:46 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_error_11(t_asm *data)
{
	int	error;

	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	error = data->error;
	free(data);
	if (ft_dprintf(2, "Error: Unknown execution (line %d)\n", error) < 0)
		ft_perror("Error");
	exit(EXIT_FAILURE);
}

void	asm_error_12(t_asm *data)
{
	int	error;

	get_next_line(data->fd, NULL);
	asm_labs_del(data->labs);
	close(data->fd);
	free(data->file);
	free(data->line);
	error = data->error;
	free(data);
	if (ft_dprintf(2, "Error: Invalid reg (line %d)\n", error) < 0)
		ft_perror("Error");
	exit(EXIT_FAILURE);
}
