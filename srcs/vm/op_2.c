/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:48:24 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/27 01:13:38 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void			sub_op(t_process *proc)
{
	int res;

	res = proc->regs[proc->args_value[0] - 1] - proc->regs[proc->args_value[1] - 1];
	proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = res;
	if (vm.log_level & OPERA)
		ft_printf("P %d | sub r%d r%d r%d\n", proc->proc_id,
				  proc->args_value[0], proc->args_value[1], proc->args_value[2]);
}

void			and_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) & get_arg_op(proc, 1);
	proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (DEBUG)
		ft_printf("proc id - %d: and: arg1 = %d arg2 = %d res = %X\n", proc->proc_id, proc->regs[proc->args_value[0] - 1], proc->regs[proc->args_value[1] - 1], res);
}

void			or_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) | get_arg_op(proc, 1);
	proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (DEBUG)
		ft_printf("proc id - %d: or: arg1 = %d arg2 = %d res = %X\n", proc->proc_id, proc->regs[proc->args_value[0] - 1], proc->regs[proc->args_value[1] - 1], res);
}

void			xor_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) ^ get_arg_op(proc, 1);
	proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (DEBUG)
		ft_printf("proc id - %d: xor: arg1 = %d arg2 = %d res = %X\n", proc->proc_id, proc->regs[proc->args_value[0] - 1], proc->regs[proc->args_value[1] - 1], res);
}
