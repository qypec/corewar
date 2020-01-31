/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:38:06 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/27 08:46:26 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void	ldi_op(t_process *proc)
{
    proc->regs[proc->args_value[2] - 1] = get_int32_from_mem(
			position_correction(proc->pos + (int)(get_arg_op(proc, 0) +
												   get_arg_op(proc, 1))) % IDX_MOD, 0);
	if (vm.log_level & OPERA)
		universal_op_log(proc, (int)(get_arg_op(proc,0)), (int)(get_arg_op(proc,1)), proc->args_value[2]);
}

void	sti_op(t_process *proc) //TODO Данная операция может записывать id в arena_id
{
	int addr;
	int i;
	unsigned char *temp;

	i = -1;
	temp = (unsigned char*)&proc->regs[proc->args_value[0] - 1];
	addr = position_correction(proc->pos + ((int)get_arg_op(proc,1) + (int)get_arg_op(proc,2)) % IDX_MOD);
	while (++i < REG_SIZE)
	{
        vm.arena[addr + i] = temp[3 - i];
        vm.arena_id[addr + i] = proc->player_id;
    }
	if (vm.log_level & OPERA)
		universal_op_log(proc, (int) proc->args_value[0], (int) get_arg_op(proc, 1), (int) get_arg_op(proc, 2));
}

void	fork_op(t_process *proc)
{
	t_process	*new;
	int 		addr;
	int         i;

	i = -1;
	addr = position_correction(proc->pos + proc->args_value[0] % IDX_MOD);
	if (!(new = create_process(proc->player_id, addr)))
		return ;
	while (++i < REG_NUMBER)
	    new->regs[i] = proc->regs[i];
	new->carry = proc->carry;

	new->live_incycle = proc->live_incycle;
	if (vm.log_level & OPERA)
		ft_printf("P%5d | fork %d (%d)\n", proc->proc_id,  proc->args_value[0], addr);
}

void	lld_op(t_process *proc)
{
    if (proc->args[0] == T_DIR)
        proc->regs[proc->args_value[1] - 1] = proc->args_value[0];
    else
        proc->regs[proc->args_value[1] - 1] = get_int32_from_mem(proc->pos + proc->args_value[0], 1);
    if (!proc->regs[proc->args_value[1] - 1])
        proc->carry = 1;
    else
        proc->carry = 0;
	if (vm.log_level & OPERA)
		universal_op_log(proc, (int)get_arg_op(proc, 0), proc->args_value[1], 0);
}

void	lldi_op(t_process *proc)//TODO надо чекнуть
{
    proc->regs[proc->args_value[2] - 1] = get_int32_from_mem(proc->pos +
															 (int) (get_arg_op(proc, 0) + get_arg_op(proc, 1)), 1);
    proc->carry = (!proc->regs[proc->args_value[2] - 1]) ? 1 : 0;
	if (vm.log_level & OPERA)
		universal_op_log(proc, (int)get_arg_op(proc, 0), (int)get_arg_op(proc, 1), proc->args_value[2]);
}

void	lfork_op(t_process *proc)
{
	t_process	*new;
	int 		addr;
	int 		i;

	addr = position_correction(proc->pos + proc->args_value[0]);
	i = -1;
	if (!(new = create_process(proc->player_id, addr)))
		return ;
    while (++i < REG_NUMBER)
        new->regs[i] = proc->regs[i];
	new->carry = proc->carry;
	new->live_incycle = proc->live_incycle;
	if (vm.log_level & OPERA)
		ft_printf("P%5d | lfork %d (%d)\n", proc->proc_id,  proc->args_value[0], addr);
}

void	aff_op(t_process *proc)
{
    if (vm.af)
        ft_putchar((char)proc->regs[proc->args_value[0] - 1]);
}