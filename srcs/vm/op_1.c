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

	number = get_int32_from_mem(proc->pc + 1, 1);
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
		ft_printf("proc id - %d: live op - %d\n", proc->proc_id, number);
}

void	zjmp_op(t_process *proc)
{
	if (proc->carry == 1)
	{
		proc->pc = proc->pc + get_int16_from_mem(proc->pc + 1) % IDX_MOD;
		if (DEBUG)
			ft_printf("proc id - %d: zjmp op - %d\n", proc->proc_id, get_int16_from_mem(proc->pc + 1));
	}
	else if (DEBUG)
		ft_printf("proc id - %d: zjmp op carry - %d\n", proc->proc_id, proc->carry);
}

void	ld_op(t_process *proc)
{
	int number;

	number = -1;
	if (proc->args[0] == T_DIR_ARG)
	{
		number = proc->args_value[0]; // for debug
		proc->regs[proc->args_value[1] - 1] = number;
		if (!proc->args_value[0])
			proc->carry = 1;
	}
	else if (proc->args[0] == T_IND_ARG)
	{
		number = get_int32_from_mem(proc->pc +
				(int)proc->args_value[0], 0) % IDX_MOD;
		proc->regs[proc->args_value[1] - 1] = number;
		if (!number)
			proc->carry = 1;
	}
	if (DEBUG)
		ft_printf("proc id - %d: ld op: num - %d reg - %d\n", proc->proc_id, number, proc->args_value[1]);
}
