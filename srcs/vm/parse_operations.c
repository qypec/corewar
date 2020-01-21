/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:04:38 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/21 19:50:56 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_ops.h>
#include "../../incs/corewar.h"

int 		check_args_type(unsigned int arg_code, const int *arg_types)
{
	int 	i;

	i = -1;
	while (++i < 3)
		if (arg_code == arg_types[i])
			return (1);
	return (0);
}

void 		process_args_code(t_process *proc)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (!check_args_type((((*(vm.arena + proc->pos + 1u)) &
							   (192u >> (unsigned) (i * 2)))) >> (6u - (unsigned) (i * 2)),
							 op_tab[proc->op - 1].args_types + i * 3))
		{
			proc->op = 0;
			proc->pc = 1;
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

	i = 0;
	offset = (op_tab[proc->op].has_args_code) ? 2 : 0; // смещение при наличии на 1 байт значения аргументов
	size = 0;
	while (++i < 3)
	{
		size = (proc->args[i] == T_REG || proc->args[i] == T_IND) ? proc->args[i] : size;
		size = (proc->args[i] == T_DIR) ? 4 / (op_tab[proc->op].dir_size + 1) : size;
		proc->args_value[i] = (proc->args[i] == T_REG) ? vm.arena[proc->pos + offset] : 0;
		proc->args_value[i] = (proc->args[i] == T_IND) ?  : 0;
		proc->args_value[i] = (proc->args[i] == T_DIR) ?  : 0;
		offset += size;
	}
	return (0);
}

//int 					check_regs(t_process *proc);
//
//int 					move_process(t_process *proc);