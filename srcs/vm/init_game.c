/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:39:55 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/20 17:46:54 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

int 	init_game(void)
{
	int i;
	int j;
	int k;
	int step;

	i = 0;
	j = 0;
	step = MEM_SIZE / vm.players_sum;
	while (++i <= MAX_PLAYERS)
	{
		k = 0;
		if (vm.players[i].id)
		{
			k = (j) ? 1 : 0;
			ft_memcpy(vm.arena + (j * step - k), vm.players[i].code, vm.players[i].code_size);
			if (!create_process(i, j * step - k))
				return (0);
			++j;
		}
	}
	return (1);
}

//void	init_op_selector(void)
//{
//	vm.ops[1] = live_op();
//	vm.ops[2] = ld_op();
//	vm.ops[3] = st_op();
//	vm.ops[4] = add_op();
//	vm.ops[5] = sub_op();
//	vm.ops[6] = and_op();
//	vm.ops[7] = or_op();
//	vm.ops[8] = xor_op();
//	vm.ops[9] = zjmp_op();
//	vm.ops[10] = ldi_op();
//	vm.ops[11] = sti_op();
//	vm.ops[12] = fork_op();
//	vm.ops[13] = lld_op();
//	vm.ops[14] = lldi_op();
//	vm.ops[15] = lfork_op();
//	vm.ops[16] = aff_op();
//}