/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:04:38 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/23 18:48:16 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_ops.h"
#include "corewar.h"

unsigned int 		check_args_type(unsigned int arg_code, const int *arg_types, t_process *proc, int j)
{
	int 	i;

	i = -1;
	if (proc->op == 3)
		proc->op = proc->op;
	while (++i < 3)
		if (j < op_tab[proc->op - 1].argc && arg_code == arg_types[i] && arg_code != 0)
		{
			proc->args[j] = arg_code;
			return (1);
		}
		else if (arg_code == 0 && j >= op_tab[proc->op - 1].argc)
			return (1);
	return (0);
}

int calc_args_size(int i, t_process *proc, int op_code)
{
	int	size;

	size = 0;
	size = (proc->args[i] == T_REG) ? 1 : size;
	size = (proc->args[i] == T_IND) ? 2 : size;
	size = (proc->args[i] == T_DIR) ? 4 / (op_tab[op_code - 1].dir_size + 1) : size;
	return (size);
}

void 		process_args_code(t_process *proc)
{
	int 			i;

	i = -1;
	while (++i < 4)
	{
		if (!check_args_type((*(vm.arena + position_correction(proc->pos + 1u))
		& (192u >> (unsigned) (i * 2))) >> (6u - (unsigned) (i * 2)),
				op_tab[proc->op - 1].args_types + i * 3, proc, i))
		{
			proc->op = 0;
			proc->pc = 1;
			return ;
		}
	}
}

int parse_args_values(t_process *proc, int op, int position, int flag)
{
	int             i;
	int             offset;
	unsigned int    size;
	unsigned int    index;

	i = -1;
	offset = (op_tab[op - 1].has_args_code) ? 2 : 1;
	while (++i < op_tab[op - 1].argc)
	{
		size = calc_args_size(i, proc, op);
		index = position_correction(position + offset);
		proc->args_value[i] = (proc->args[i] == T_REG) ? (int)vm.arena[index] : proc->args_value[i];
		proc->args_value[i] = (proc->args[i] == T_IND) ? get_int16_from_mem((int) index, 0) : proc->args_value[i];
		proc->args_value[i] = (proc->args[i] == T_DIR && op_tab[op - 1].dir_size == 0)
				? get_int32_from_mem((int) index,0) : proc->args_value[i];
		proc->args_value[i] = (proc->args[i] == T_DIR && op_tab[op - 1].dir_size == 1)
				? get_int16_from_mem((int) index,0) : proc->args_value[i];
		offset += (int)size;
	}
	if (flag)
		proc->pc += offset;
	return (offset);
}

int check_regs(t_process *proc, int op)
{
	int i;
	int ok;

	i = -1;
	ok = 1;
	while (++i < op_tab[op - 1].argc)
		if (proc->args[i] == T_REG)
			if (proc->args_value[i] < 1 || proc->args_value[i] > 16)
				ok = 0;
	return (ok);
}