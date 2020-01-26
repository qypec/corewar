/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:48:24 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/23 19:48:28 by ergottli         ###   ########.fr       */
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
	if (vm.log_level & OPERA)
		bit_op_log(proc, get_arg_op(proc, 0), get_arg_op(proc, 1));
}

void			or_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) | get_arg_op(proc, 1);
    proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (vm.log_level & OPERA)
		bit_op_log(proc, get_arg_op(proc, 0), get_arg_op(proc, 1));
}

void			xor_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) ^ get_arg_op(proc, 1);
    proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (vm.log_level & OPERA)
		bit_op_log(proc, get_arg_op(proc, 0), get_arg_op(proc, 1));
}
