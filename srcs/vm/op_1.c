/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:09:16 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/20 19:35:08 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void	live_op(t_process *proc)
{
	int *number;

	++proc->live_incycle;
	number = (int*)(vm.arena + proc->pos + 1);
	number &=
	if (*number > 0 && *number <= MAX_PLAYERS && vm.players[*number].id)
	{
		++vm.players[*number].is_alive;
		++vm.players[*number].lives_all;
		++vm.players[*number].lives_last;
		++vm.players[*number].lives_current;
		++vm.lives_in_round;
		vm.last_alive = *number;
	}

}
