/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_options_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:25:21 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 14:45:26 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int		ft_full_char(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		if (str[i++] != c)
			return (0);
	return (1);
}

void	ft_select_player(char *str, t_param *p, t_options *s)
{
	char	*tmp;
	int		z;

	z = -1;
	p->param = 1;
	p->opt.param = 0;
	p->opt.sp = 0;
	(void)s;
	if ((tmp = ft_trim_int(str)))
	{
		if ((((t_ui)ft_atol(tmp)) <= 4294967295 && ((t_ui)ft_atol(tmp)) > 0)
				|| (!((t_ui)ft_atol(tmp)) && ft_full_char(tmp, '0')))
		{
			while (++z < 4 && p->nchamp[z].param)
				if (p->nchamp[z].num_player == ((unsigned int)ft_atol(tmp)))
					ft_perror("already fixe num champ");
			p->nchamp[p->nb_champ].param = 1;
			p->nchamp[p->nb_champ].num_player = (unsigned int)ft_atol(tmp);
		}
		else
			ft_perror("invalid param");
		ft_strdel(&tmp);
	}
	else
		ft_perror("invalid number");
}

void	ft_select_dump(char *str, t_param *p, t_options *s)
{
	char		*tmp;
	static int	i = 0;

	(void)s;
	if (i)
		ft_perror("double dump");
	i = 1;
	p->dump = 1;
	p->opt.param = 0;
	if (!(str[0] == '-') && (tmp = ft_trim_int(str)))
	{
		if ((((unsigned int)ft_atol(tmp)) <= 4294967295
				&& ((unsigned int)ft_atol(tmp)) > 0)
				|| (!((unsigned int)ft_atol(tmp)) && ft_full_char(tmp, '0')))
			p->dmp = (unsigned int)ft_atol(tmp);
		else
			ft_perror("invalid param");
		ft_strdel(&tmp);
	}
	else
		ft_perror("invalid number");
}

void	ft_select_periodic(char *str, t_param *p, t_options *s)
{
	char	*tmp;

	(void)s;
	p->opt.param = 0;
	if (!(str[0] == '-') && (tmp = ft_trim_int(str)))
	{
		if ((((unsigned int)ft_atol(tmp)) <= 4294967295
				&& ((unsigned int)ft_atol(tmp)) > 0)
				|| (!((unsigned int)ft_atol(tmp)) && ft_full_char(tmp, '0')))
			p->periodic = (unsigned int)ft_atol(tmp);
		else
			ft_perror("invalid param");
		ft_strdel(&tmp);
	}
	else
		ft_perror("invalid number");
}
