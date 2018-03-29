/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pointer_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:16:51 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 15:02:53 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_set_fd(char *str, t_param *p, t_options *s)
{
	(void)s;
	if (p->nb_champ < 4)
	{
		p->opt.param = 0;
		if ((p->nchamp[p->nb_champ++].fd = open(str, O_RDONLY)) > 0)
			return ;
	}
	ft_perror("invalid .cor");
}

void	ft_set_option(char *str, t_param *p, t_options *s)
{
	int		param;

	param = 0;
	if (ft_strequ("-n", str) && (param = 1))
		ft_isactive(p->opt.sp, &p->opt.sp, 1);
	else if (ft_strequ("-d", str) && (param = 1))
		ft_isactive(p->opt.d, &p->opt.d, 1);
	else if (ft_strequ("-s", str) && (param = 1))
		ft_isactive(p->opt.s, &p->opt.s, 1);
	else
		ft_perror("Invalid params");
	if (param)
		p->opt.param = 1;
	(void)s;
}

void	ft_set_optionparam(char *str, t_param *p, t_options *s)
{
	if (!p->param && p->opt.sp)
		ft_select_player(str, p, s);
	else if (p->opt.d)
		ft_select_dump(str, p, s);
	else if (p->opt.s)
		ft_select_periodic(str, p, s);
	else
		ft_perror("Invalid param");
	(void)s;
}

void	ft_error(char *str, t_param *p, t_options *s)
{
	(void)str;
	(void)p;
	(void)s;
	ft_perror("error param");
}
