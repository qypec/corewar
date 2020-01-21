/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:04:38 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/21 20:15:18 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_ops.h>
#include "../../incs/corewar.h"

unsigned int 		check_args_type(unsigned int arg_code, const int *arg_types)
{
	int 	i;

	i = -1;
	while (++i < 3)
		if (arg_code == arg_types[i])
			return (arg_code);
	return (0);
}

int 					calc_args_size(int i, t_process *proc)
{
	int	size;

	size = 0;
	size = (proc->args[i] == T_REG) ? 1 : size;
	size = (proc->args[i] == T_IND) ? 2 : size;
	size = (proc->args[i] == T_DIR) ? 4 / (op_tab[proc->op].dir_size + 1) : size;
	return (size);
}

void 		process_args_code(t_process *proc)
{
	int 			i;
	unsigned int	arg_code;

	i = -1;
	while (++i < 4)
	{
		if ((arg_code = check_args_type((((*(vm.arena + proc->pos + 1u)) &
							   (192u >> (unsigned) (i * 2)))) >> (6u - (unsigned) (i * 2)),
							 op_tab[proc->op - 1].args_types + i * 3)))
		{
			proc->args[i] = arg_code;
			proc->pc += calc_args_size(i, proc);
		}
		else
		{
			proc->op = 0;
			proc->pc = 1;
			return ;
		}
	}
}

/*
 * 			{T_REG, T_REG, T_REG}
 */

/*
 * 	live	|	T_REG 	|	T_DIR	|	|	|	T_IND	|	|
 * 			|	1b		|	4b		|	|	|	2b		|	|
 */

int 					parse_args_values(t_process *proc)
{
	int	i;
	int offset;
	unsigned int size;

	i = -1;
	offset = (op_tab[proc->op].has_args_code) ? 2 : 1; // смещение при наличии на 1 байт значения аргументов
	while (++i < 3)
	{
		size = calc_args_size(i, proc);
		proc->args_value[i] = (proc->args[i] == T_REG) ? (int)vm.arena[proc->pos + offset] : 0;
		proc->args_value[i] = (proc->args[i] == T_IND) ? get_int16_from_mem(proc->pos + offset) : 0;
		proc->args_value[i] = (proc->args[i] == T_DIR) ? get_int32_from_mem(proc->pos + offset, 0) : 0;
		offset += (int)size;
	}
	return (1);
}

int 	check_regs(t_process *proc)
{
	int i;
	int ok;

	i = -1;
	ok = 1;
	while (++i < 3)
	{
		if (proc->args[i] == T_REG)
			if (proc->args_value[i] < 1 || proc->args_value[i] > 16)
				ok = 0;
	}
	return (ok);
}