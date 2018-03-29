/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:58:35 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/02 10:55:04 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_error(int value, char *msg, void *to_free)
{
	if (to_free)
		free(to_free);
	ft_putendl_fd(msg, 2);
	return (value);
}
