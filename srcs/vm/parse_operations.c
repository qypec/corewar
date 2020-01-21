/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:04:38 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/21 15:07:20 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void set_args_code(t_process *proc)
{
	unsigned int 	i;

	i = -1;
	while (++i < 4)
	{
		proc->args[i] = ((unsigned int)vm.arena[proc->pos + 1] >> (6u - i * 2)) & (3u);
		if (DEBUG)
		{
			ft_printf("proc id - %d -- proc->args[%d] = %d\n", proc->proc_id, i, proc->args[i]);
		}
	}
}

int	check_op_args(t_process *proc)
{
	int 	ok;

	ok = 0;
	if (proc->args[3])
		return (0);
	if (proc->op == 2 || proc->op == 13) // ld, lld
		ok = ((proc->args[0] == T_DIR_ARG || proc->args[0] == T_IND_ARG) && proc->args[1] == T_REG_ARG && !proc->args[2]) ? 1 : 0;
	if (proc->op == 3) // st,
		ok = ((proc->args[0] == T_REG) && (proc->args[1] == T_REG_ARG || proc->args[1] == T_IND_ARG) && !proc->args[2]) ? 1 : 0;
	if (proc->op == 4 || proc->op == 5) // add, sub
		ok = ((proc->args[0] == T_REG) && proc->args[1] == T_REG_ARG && proc->args[2] == T_REG_ARG) ? 1 : 0;
	if (proc->op == 6 || proc->op == 7 || proc->op == 8) // and, or, xor
		ok = ((proc->args[0] == T_DIR_ARG || proc->args[0] == T_IND_ARG || proc->args[0] == T_REG_ARG)
			  && (proc->args[1] == T_DIR_ARG || proc->args[1] == T_IND_ARG || proc->args[1] == T_REG_ARG)
			  && proc->args[2] == T_REG_ARG) ? 1 : 0;
	if (proc->op == 10 || proc->op == 14) // ldi, lldi
		ok = ((proc->args[0] == T_DIR_ARG || proc->args[0] == T_IND_ARG || proc->args[0] == T_REG_ARG)
			  && (proc->args[1] == T_DIR_ARG || proc->args[1] == T_REG_ARG) && proc->args[2] == T_REG_ARG) ? 1 : 0;
	if (proc->op == 11) // sti
		ok = (proc->args[0] == T_REG
			  && (proc->args[1] == T_DIR_ARG || proc->args[1] == T_IND_ARG || proc->args[1] == T_REG_ARG)
			  && (proc->args[2] == T_REG_ARG || proc->args[2] == T_DIR_ARG)) ? 1 : 0;
	if (proc->op == 16) // aff
		ok = (proc->args[0] == T_REG && !proc->args[1] && !proc->args[2]) ? 1 : 0;
	return (ok);
}

int 					parse_args_values(t_process *proc);
int 					check_regs(t_process *proc);
int 					move_process(t_process *proc);