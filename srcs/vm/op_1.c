/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:09:16 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/22 18:07:26 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void	live_op(t_process *proc)
{
	int				number;
	int				player_index;

    ++vm.lives_in_round;
    ++proc->live_incycle;
	number = get_int32_from_mem(proc->pos + 1);
	player_index = number * -1;
	if (player_index > 0 && player_index <= MAX_PLAYERS &&
	vm.players[player_index].id)
	{
		++vm.players[player_index].is_alive;
		++vm.players[player_index].lives_all;
		++vm.players[player_index].lives_last;
		++vm.players[player_index].lives_current;
		vm.last_alive = &vm.players[player_index];
	}
	if (DEBUG)
		ft_printf("proc id - %d: live op - %d\n", proc->proc_id, number);
}

void	zjmp_op(t_process *proc)
{
	if (proc->carry == 1)
	{
		proc->pc = get_int16_from_mem(proc->pos + 1) % IDX_MOD;
		if (!proc->pc)
		    proc->pos = 0;
		if (DEBUG && proc->carry)
			ft_printf("proc id - %d: pos = %d zjmp op - %d\n", proc->proc_id, proc->pos, proc->pc);
	}
	else if (DEBUG && proc->carry)
		ft_printf("proc id - %d: zjmp op carry - %d\n",
				proc->proc_id, proc->carry);
//    (DEBUG) ? print_arena(position_correction(proc->pos + proc->pc), 1, proc->pos, 1) : 0;
}

void	ld_op(t_process *proc)
{
    if (vm.checks == 148) {
        vm.checks = 148;
		print_arena(proc->pos, 0, 0, 0);
    }
    proc->regs[proc->args_value[1] - 1] = (int)get_arg_op(proc, 0);
    if (!proc->args_value[0])
			proc->carry = 1;
    else
        proc->carry = 0;
    if (DEBUG)
		ft_printf("proc id - %d: ld op: num - %d reg - %d\n",
				proc->proc_id, proc->args_value[0], proc->args_value[1]);
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
    if (DEBUG)
        ft_printf("proc id - %d: proc->pos = %d : st op: arg1 - %X arg2 - %X res = %X addr - %d\n",
                  proc->proc_id, proc->pos, get_arg_op(proc,1), get_arg_op(proc,2), proc->regs[proc->args_value[0] - 1], proc->regs[proc->args_value[0] - 1]);
}

void	add_op(t_process *proc)
{
	int res;

	res = proc->regs[proc->args_value[0] - 1] + proc->regs[proc->args_value[1] - 1];
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->regs[proc->args_value[2] - 1] = res;
    if (DEBUG)
        ft_printf("proc id - %d: add op: arg1 = %d arg2 = %d res = %d\n", proc->proc_id, proc->regs[proc->args_value[0] - 1], proc->regs[proc->args_value[1] - 1], res);
}
