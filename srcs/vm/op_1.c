/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:09:16 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:07:30 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void	live_op(t_process *proc)
{
	int				number;
	unsigned char	buf[4];
	unsigned char	*cur_position;

	cur_position = vm.arena + proc->pc + 1;
	buf[3] = *(cur_position);
	buf[2] = *(cur_position + 1);
	buf[1] = *(cur_position + 2);
	buf[0] = *(cur_position + 3);
	buf[0] &= 127u;
	number = *((int*)buf);
	if (number > 0 && number <= MAX_PLAYERS && vm.players[number].id)
	{
		++vm.players[number].is_alive;
		++vm.players[number].lives_all;
		++vm.players[number].lives_last;
		++vm.players[number].lives_current;
		++vm.lives_in_round;
		vm.last_alive = &vm.players[number];
		++proc->live_incycle;
	}
	if (DEBUG)
	{
		ft_printf("proc id - %d: live op - %d\n", proc->proc_id, number);
	}
}

void	zjmp_op(t_process *proc)
{
	unsigned char	buf[2];

	if (proc->carry == 1)
	{
		buf[1] = *(vm.arena + proc->pc + 1);
		buf[1] = *(vm.arena + proc->pc + 2);
		proc->pc = proc->pc + (*((int16_t*)buf)) % IDX_MOD;
	}
}
