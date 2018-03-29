/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:56:25 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/11 12:00:12 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;

	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	else
		sign = 1;
	if ((n / 10) != 0)
		ft_putnbr_fd(sign * (n / 10), fd);
	ft_putchar_fd((sign * (n % 10)) + '0', fd);
}
