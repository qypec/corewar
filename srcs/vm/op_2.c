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
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->regs[proc->args_value[2] - 1] = res;
}

void			and_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) & get_arg_op(proc, 1);
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->regs[proc->args[2] - 1] = (int)res;
}

void			or_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) | get_arg_op(proc, 1);
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->regs[proc->args[2] - 1] = (int)res;
}

void			xor_op(t_process *proc)
{
	unsigned int res;

	res = get_arg_op(proc, 0) ^ get_arg_op(proc, 1);
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->regs[proc->args[2] - 1] = (int)res;
}
