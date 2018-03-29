/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:25:53 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/25 16:40:25 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLES_H
# define CYCLES_H
# include "libft_adv.h"
# include "process.h"

typedef struct		s_timer
{
	unsigned int		cycle;
	unsigned int		next_check;
	unsigned int		to_die;
	unsigned int		fail_check;
}					t_timer;

t_timer				cycle_init(void);
t_bool				cycle_count(t_timer *timer, t_proc **proc);

#endif
