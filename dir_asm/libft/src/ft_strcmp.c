/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:37:37 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:37:38 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(const char *s1, const char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
