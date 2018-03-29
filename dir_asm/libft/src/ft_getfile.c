/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:49:18 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 16:46:39 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_file(int fd, t_list **begin_list)
{
	t_list	*new;
	char	*line;
	int		ret;

	ret = 0;
	while (ret != -1 && (ret = get_next_line(fd, &line)) > 0)
	{
		if ((new = ft_lstnew(NULL, 0)))
		{
			new->content = (void*)line;
			if (*begin_list)
				ft_lstadd_back(*begin_list, new);
			else
				*begin_list = new;
		}
		else
			ret = -1;
	}
	if (ret == -1)
	{
		if (*begin_list)
			ft_lstdel(begin_list, &ft_memdel_bis);
		ft_perror("Error");
	}
}

t_list		*ft_getfile(char *file)
{
	t_list		*begin_list;
	int			fd;

	begin_list = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_perror("Error");
	if (lseek(fd, 0, SEEK_SET) < 0)
		ft_perror("Error");
	get_file(fd, &begin_list);
	if (close(fd) < 0)
	{
		if (begin_list)
			ft_lstdel(&begin_list, &ft_memdel_bis);
		ft_perror("Error");
	}
	return (begin_list);
}
