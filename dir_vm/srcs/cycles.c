/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:08:29 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/16 16:33:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "cycles.h"

t_timer			cycle_init(void)
{
	t_timer		res;

	res.cycle = 1;
	res.next_check = CYCLE_TO_DIE;
	res.to_die = CYCLE_TO_DIE;
	res.fail_check = 0;
	return (res);
}

t_bool			cycle_count(t_timer *timer, t_proc **proc)
{
	if (!(*proc))
		return (FALSE);
	if (timer->cycle >= timer->next_check)
	{
		if (proc_alive(proc) >= NBR_LIVE && !(timer->fail_check = 0))
		{
			timer->to_die -=
				CYCLE_DELTA > timer->to_die ? timer->to_die : CYCLE_DELTA;
		}
		else
		{
			timer->fail_check += 1;
			if (timer->fail_check == MAX_CHECKS && !(timer->fail_check = 0))
			{
				timer->to_die -=
					CYCLE_DELTA > timer->to_die ? timer->to_die : CYCLE_DELTA;
			}
		}
		timer->next_check += timer->to_die;
	}
	timer->cycle += 1;
	return (TRUE);
}
