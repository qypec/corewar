/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:56:12 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/27 05:56:13 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_process(void)
{
	t_process	*temp;
	int 		i;

	temp = vm.processes;
	while (temp)
	{
		ft_printf("\n\n\n");
		ft_printf(ANSI_B_RED"proc_id = %d\n"ANSI_RESET, temp->proc_id);
		ft_printf("player_id = %d\n", temp->player_id);
		ft_printf("pos = %d\n", temp->pos);
		ft_printf("pc = %d\n", temp->pc);
		ft_printf("op = %d\n", temp->op);
		ft_printf(ANSI_B_GREEN"ARGS:\n"ANSI_RESET);
		i = -1;
		while (++i < 3)
			ft_printf("args[%d] = %d\n", i, temp->args[i]);
		ft_printf("carry = %d\n", temp->carry);
		ft_printf("delay = %d\n", temp->delay);
		ft_printf("live_incycle = %d\n", temp->live_incycle);
		ft_printf(ANSI_B_GREEN"REGS:\n"ANSI_RESET);
		i = -1;
		while (++i < REG_NUMBER)
			ft_printf("regs[%d] = %d\n", i, temp->regs[i]);
		ft_printf("\n\n\n");
		temp = temp->next;
	}
}

void	print_arena(int pos, int print_op, int op_pos, int size)
{
	int 	i;
	int 	j;
	int 	k;
	int     row;
	int 	bit;


	i = 0;
	row = 0;
	k = -1;
	if (vm.dump)
		bit = (vm.dump) ? vm.dump * 32 : 32;
	if (vm.s)
		bit = (vm.s) ? vm.s * 32 : 32;
	ft_printf("0x");
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("%#.4x : ", row * bit);
		while (++j < bit)
		{
		    if (DEBUG)
            {
                if (print_op && i >= op_pos && i < op_pos + size)
                    ft_printf(ANSI_B_RED"%02x "ANSI_RESET, vm.arena[i]);
                else if (i >= pos && ++k < 4)
                    ft_printf(ANSI_B_GREEN"%02x "ANSI_RESET, vm.arena[i]);
                else
                    ft_printf("%02x ", vm.arena[i]);
            }
		    else
                ft_printf("%02x ", vm.arena[i]);
			++i;
		}
		ft_printf("\n");
		++row;
	}
	if (vm.dump_cycle == vm.cycles_all && vm.dump)
	    exit(0);
	else if (vm.s)
	{
		while (1)
			if (getchar() == '\n')
				break;
//		vm.dump_cycle += vm.dump_step;
		vm.dump_cycle += 1;
	}
}