/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:38:06 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/23 19:10:02 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void	ldi_op(t_process *proc)
{
	int res;

	if (proc->args[0] == T_REG && proc->args[1] == T_REG)
	{
		res = (proc->regs[proc->args_value[0] - 1] + proc->regs[proc->args_value[1] - 1]) % IDX_MOD;
		proc->regs[proc->args_value[2] - 1] = res;
	}
	else if (proc->args[0] == T_DIR && proc->args[1] == T_DIR)
	{
		res = (proc->args_value[0] + proc->args_value[1]) % IDX_MOD;
		proc->regs[proc->args_value[2] - 1] = res;
	}
	else if (proc->args[0] == T_IND)
	{
		res = get_int32_from_mem(proc->pos +
								 (int)proc->args_value[0], 0) % IDX_MOD;
		proc->regs[proc->args_value[2] - 1] = res;
	}
	if (DEBUG)
		ft_printf("proc id - %d: ldi op: num - %d reg - %d\n", proc->proc_id, res, proc->regs[proc->args_value[2] - 1]);
}

void	sti_op(t_process *proc)
{
	int addr;

	addr = -1;
	if (proc->args[1] == T_DIR && proc->args[2] == T_DIR)
		addr = proc->pos + (proc->args_value[1] + proc->args_value[2]) % IDX_MOD;
	else if (proc->args[1] == T_REG && proc->args[2] == T_REG)
		addr = proc->pos + (proc->regs[proc->args_value[1] - 1]
				+ proc->regs[proc->args_value[2] - 1]) % IDX_MOD;
	else if (proc->args[0] == T_IND)
		addr = get_int32_from_mem(proc->pos
				+ (int)proc->args_value[2], 0) % IDX_MOD;
	vm.arena[addr] = proc->regs[proc->args_value[0] - 1];
	vm.arena_id[addr] = proc->player_id;
}

void	fork_op(t_process *proc)
{
	t_process	*new;
	int 		addr;

	addr = proc->args_value[0] % IDX_MOD;
	if (!(new = create_process(proc->player_id, addr)))
		return ;
}

void	lld_op(t_process *proc)
{
	int res;

	res = -1;
	if (proc->args[0] == T_DIR)
	{
		res = proc->args_value[0];
		proc->regs[proc->args_value[1] - 1] = res;
		if (!proc->args_value[0])
			proc->carry = 1;
	}
	else if (proc->args[0] == T_IND)
	{
		res = get_int32_from_mem(proc->pos
								 + (int)proc->args_value[0], 0);
		proc->regs[proc->args_value[1] - 1] = res;
		if (!res)
			proc->carry = 1;
	}
	if (DEBUG)
		ft_printf("proc id - %d: lld op: num - %d reg - %d\n", proc->proc_id, res, proc->args_value[1]);
}

void	lldi_op(t_process *proc)
{
	int res;

	res = -1;
	if (proc->args[0] == T_REG && proc->args[1] == T_REG)
	{
		res = proc->regs[proc->args_value[0] - 1] + proc->regs[proc->args_value[1] - 1];
		proc->regs[proc->args_value[2] - 1] = res;
	}
	else if (proc->args[0] == T_DIR && proc->args[1] == T_DIR)
	{
		res = proc->args_value[0] + proc->args_value[1];
		proc->regs[proc->args_value[2] - 1] = res;
	}
	else if (proc->args[0] == T_IND)
	{
		res = get_int32_from_mem(proc->pos
				+ (int)proc->args_value[0], 0) % IDX_MOD;
		proc->regs[proc->args_value[2] - 1] = res;
	}
	if (DEBUG)
		ft_printf("proc id - %d: lldi op: num - %d reg - %d\n", proc->proc_id, res, proc->regs[proc->args_value[2] - 1]);
}

void	lfork_op(t_process *proc);
void	aff_op(t_process *proc);