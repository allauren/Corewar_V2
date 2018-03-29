/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_sec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:25:44 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 18:59:57 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi_sec(const char *str)
{
	long			ret;
	int				sign;
	int				index;

	index = 0;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0' && *str)
		str++;
	while (ft_isdigit(str[index]))
		index++;
	if ((index == 10 && (((str[index - 1] - '0' > 7 && sign == 1) ||
	(str[index - 1] - '0' > 8 && sign == -1)) &&
	!ft_strncmp("214748364", str, 9))) || index > 10)
		return (-1);
	index = 0;
	while (ft_isdigit(str[index]))
		ret = ret * 10 + str[index++] - '0';
	return ((int)ret * sign);
}
