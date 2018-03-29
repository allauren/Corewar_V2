/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:32:29 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 16:50:09 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_create_file(char *file, int size, char *name_cor)
{
	int		fd;

	if ((fd = open(name_cor, O_WRONLY | O_CREAT | O_TRUNC,
	S_IRUSR | S_IWUSR)) < 0)
		asm_error_4(fd, file, name_cor);
	if (write(fd, file, size) < 0)
		asm_error_4(fd, file, name_cor);
	if (close(fd) < 0)
		asm_error_4(fd, file, name_cor);
	if (ft_printf("Writing output program to %s\n", name_cor) < 0)
		asm_error_4(fd, file, name_cor);
	free(file);
	free(name_cor);
}

int			main(int ac, char **av)
{
	int		fd;
	int		size;
	char	*file;
	char	*name_cor;

	if (ac != 2 || av[1][ft_strlen(av[1]) - 1] != 's' ||
	av[1][ft_strlen(av[1]) - 2] != '.')
	{
		if (ft_putstr_fd("Usage: ./asm file.s\n", 2) < 0)
			ft_perror("Error");
	}
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_perror("Error");
		size = asm_process(fd, &file);
		if (close(fd) < 0)
			asm_error_3(file);
		if (!(name_cor = ft_strnjoin_s1(av[1], "cor", ft_strlen(av[1]) - 1)))
			asm_error_3(file);
		asm_create_file(file, size, name_cor);
	}
	return (EXIT_SUCCESS);
}
