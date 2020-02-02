/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:09:16 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/27 01:13:38 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void	live_op(t_process *proc)
{
	int				number;
	int				player_index;

	number = get_int32_from_mem(proc->pos + 1, 1);
	player_index = number * -1;
	++vm.lives_in_round;
	++proc->live_incycle;
	if (number > 0 && number <= vm.players_sum)
	{
		++vm.players[player_index].is_alive;
		++vm.players[player_index].lives_all;
		++vm.players[player_index].lives_last;
		++vm.players[player_index].lives_current;
		vm.last_alive = &vm.players[player_index];
		if (vm.log_level & LIVE)
			ft_printf("Player %d (%s) is said to be alive\n",
					  proc->player_id, vm.players[proc->player_id].name);
	}
	if (vm.log_level & OPERA)
		universal_op_log(proc, number, 0, 0);
}

void	zjmp_op(t_process *proc)
{
	int	addr;

	addr = get_int16_from_mem(proc->pos + 1, 1) % IDX_MOD;
	if (proc->carry == 1)
		proc->pc = addr;
	if (vm.log_level & OPERA)
	{
		ft_printf("P %4d | zjmp %d %s\n",
				  proc->proc_id,
				  addr,
				  (proc->carry) ? "OK" : "FAILED");
	}
}

void	ld_op(t_process *proc)
{
	proc->regs[proc->args_value[1] - 1] = (int)get_arg_op(proc, 0);
	proc->carry = proc->regs[proc->args_value[1] - 1] == 0 ? 1 : 0;
	if (vm.log_level & OPERA)
		universal_op_log(proc, proc->regs[proc->args_value[1] - 1], proc->args_value[1], proc->args_value[2]);
}

void                st_op(t_process *proc)//TODO Данная операция может записывать id в arena_id
{
	int             i;
	unsigned char   *temp;

	i = -1;
	if (proc->args[1] == T_REG)
		proc->regs[proc->args_value[1] - 1] = proc->regs[proc->args_value[0] - 1];
	else if (proc->args[1] == T_IND)
	{
		temp = (unsigned char*)&proc->regs[proc->args_value[0] - 1];
		while (++i < REG_SIZE)
		{
			vm.arena[position_correction(proc->pos + i + proc->args_value[1] % IDX_MOD)] = temp[3 - i];
			vm.arena_id[position_correction(proc->pos + i + proc->args_value[1] % IDX_MOD)] = proc->player_id;
		}
	}
	if (vm.log_level & OPERA)
	{
		proc->args[1] = T_DIR;
		universal_op_log(proc, proc->args_value[0], proc->args_value[1], proc->args_value[2]);
	}
}

void	add_op(t_process *proc)
{
	proc->regs[proc->args_value[2] - 1] = proc->regs[proc->args_value[0] - 1] + proc->regs[proc->args_value[1] - 1];
	proc->carry = proc->regs[proc->args_value[2] - 1] == 0 ? 1 : 0;
	if (vm.log_level & OPERA)
		universal_op_log(proc, proc->args_value[0], proc->args_value[1], proc->args_value[2]);
}
