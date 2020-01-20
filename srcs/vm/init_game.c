/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:39:55 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/20 16:06:12 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

int 	init_game(void)
{
	int i;
	int j;
	int step;

	i = 0;
	step = MEM_SIZE / vm.players_sum;
	while (++i < vm.players_sum)
	{
		j = 0;
		while (vm.players_temp[j].id != i)
			++j;
		ft_memcpy(vm.arena + ((i - 1) * step), vm.players_temp[j].code, vm.players_temp[j].code_size);
		if (!create_process(j, (i - 1) * step))
			return (0);
	}
	return (1);
}

void	init_op_selector(void)
{
	vm.ops[1] = exec_live();
	vm.ops[2] = ld
			st
	add
			sub
	and
			or
	xor
			zjmp
	ldi
			sti
	fork
			lld
	lldi
			lfork
	aff
}