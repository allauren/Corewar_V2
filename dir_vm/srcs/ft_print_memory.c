/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:03:20 by allauren          #+#    #+#             */
/*   Updated: 2018/03/16 17:00:58 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"

void	ft_printhex(int n)
{
	int c;

	if (n >= 16)
		ft_printhex(n / 16);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	ft_putchar(c);
}

void	ft_printchars(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	unsigned char	*t;
	int				col;

	t = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		size > 64 ? ft_printf("0x%.4x : ", i) : 0;
		col = -1;
		while (++col < 64 && (t_ui)col != size)
		{
			if (i < size)
			{
				if (t[i] < 16)
					ft_putchar('0');
				ft_printhex(t[i]);
				ft_putchar(' ');
			}
			else
				ft_putstr("  ");
			i++;
		}
		size > 64 ? ft_putchar('\n') : 0;
	}
}
