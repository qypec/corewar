/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:09:30 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/23 19:20:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live_op(t_process *proc)
{
	int				number;
	int 			player_index;

	number = get_int32_from_mem(proc->pos + 1, 0);
	player_index = number * -1;
	if (player_index > 0 && player_index <= MAX_PLAYERS && vm.players[player_index].id)
	{
		++vm.players[player_index].is_alive;
		++vm.players[player_index].lives_all;
		++vm.players[player_index].lives_last;
		++vm.players[player_index].lives_current;
		++vm.lives_in_round;
		vm.last_alive = &vm.players[player_index];
		++proc->live_incycle;
	}
	if (DEBUG)
		ft_printf("proc id - %d: live op - %d\n", proc->proc_id, number);
}

void	zjmp_op(t_process *proc)
{
	if (proc->carry == 1)
	{
		proc->pc = get_int16_from_mem(proc->pos + 1) % IDX_MOD;
		if (DEBUG)
			ft_printf("proc id - %d: zjmp op - %d\n", proc->proc_id, proc->pc);
	}
	else if (DEBUG)
		ft_printf("proc id - %d: zjmp op carry - %d\n", proc->proc_id, proc->carry);
}

void	ld_op(t_process *proc)
{
	int number;

	number = -1;
	if (proc->args[0] == T_DIR)
	{
		number = proc->args_value[0]; // for debug
		proc->regs[proc->args_value[1] - 1] = number;
		if (!proc->args_value[0])
			proc->carry = 1;
	}
	else if (proc->args[0] == T_IND)
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
