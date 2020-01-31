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
		universal_op_log(proc, proc->args_value[0], proc->args_value[1], proc->args_value[2]);
}

void			and_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) & get_arg_op(proc, 1);
    proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (vm.log_level & OPERA)
		universal_op_log(proc, proc->args_value[0], proc->args_value[1], proc->args_value[2]);
}

void			or_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) | get_arg_op(proc, 1);
    proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (vm.log_level & OPERA)
		universal_op_log(proc, proc->args_value[0], proc->args_value[1], proc->args_value[2]);
}

void			xor_op(t_process *proc)
{
	unsigned int    res;
	unsigned int    first;
    unsigned int    second;

	first = get_arg_op(proc, 0);
	second = get_arg_op(proc, 1);
	res = first ^ second;
    proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (vm.log_level & OPERA)
	{
	    proc->args[0] = 2;
	    proc->args[1] = 2; // Kostyl for log
        universal_op_log(proc, (int)first, (int)second, proc->args_value[2]);
    }
}
