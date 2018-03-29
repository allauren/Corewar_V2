/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:15:45 by allauren          #+#    #+#             */
/*   Updated: 2018/03/03 09:39:38 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

static void	ft_put_int(char *str, int base, int i, long *jack)
{
	*jack = *jack * base;
	if (str[i] >= '0' && str[i] <= '9')
		*jack = str[i] - '0' + *jack;
	else if (str[i] >= 'A' && str[i] <= 'Z')
		*jack = str[i] - 'A' + 10 + *jack;
	else
		*jack = str[i] - 'a' + 10 + *jack;
}

int			ft_atoi_base(const char *l, int base)
{
	t_atoi			s;
	static char		tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

	ft_bzero(&s, sizeof(t_atoi));
	while (l[s.i] && l[s.i] < 32)
		s.i++;
	if ((s.neg = 1) && l[s.i] == '-')
		s.neg = -1;
	if ((s.fin = 1) && (l[s.i] == '-' || l[s.i] == '+'))
		s.i++;
	while ((s.j = -1) && l[s.i] && s.fin)
	{
		while (++s.j < base)
			if ((l[s.i] == tab[s.j] || (s.j >= 10 && l[s.i] == (tab[s.j] - 32)))
					&& (s.fin = 1))
				break ;
			else
				s.fin = 0;
		if (s.fin)
			ft_put_int((char*)&l[s.i], base, 0, &s.jack);
		s.i++;
	}
	return ((int)(s.jack * s.neg));
}
