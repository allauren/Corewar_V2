/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:36:01 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/21 19:15:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(char	const *s)
{
	int	ret;

	if ((ret = write(1, s, ft_strlen(s))) >= 0)
		ret = write(1, "\n", 1);
	return (ret);
}
