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
    proc->regs[proc->args_value[2] - 1] = get_int32_from_mem(proc->pos + (int)(get_arg_op(proc,0) +
            get_arg_op(proc,1)) % IDX_MOD);
}

void	sti_op(t_process *proc) //TODO Данная операция может записывать id в arena_id
{
	int addr;

	addr = proc->pos + (int)(get_arg_op(proc,0) + get_arg_op(proc,1)) % IDX_MOD;
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
	ft_memcpy(new->regs, proc->regs, 16 * sizeof(int));
	new->carry = proc->carry;

}

void	lld_op(t_process *proc)
{
    if (proc->args[0] == T_DIR)
        proc->regs[proc->args_value[1] - 1] = proc->args_value[0];
    else
        proc->regs[proc->args_value[1] - 1] = get_int32_from_mem(proc->pos + proc->args_value[0]);
    if (!proc->args_value[0])
        proc->carry = 1;
    else
        proc->carry = 0;
	if (DEBUG)
		ft_printf("proc id - %d: lld op: reg - %d\n", proc->proc_id, proc->args_value[1]);
}

void	lldi_op(t_process *proc)
{
    proc->regs[proc->args_value[2] - 1] = get_int32_from_mem(proc->pos +
            (int)(get_arg_op(proc,0) + get_arg_op(proc,1)));
	if (DEBUG)
		ft_printf("proc id - %d: lldi op: reg - %d\n", proc->proc_id, proc->regs[proc->args_value[2] - 1]);
}

void	lfork_op(t_process *proc);

void	aff_op(t_process *proc)
{
    if (OPTIONS & AF)
        ft_putchar((char)proc->regs[proc->args_value[0] - 1]);
}