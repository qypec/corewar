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
			ft_memset(vm.arena_id + (j * step - k), vm.players[i].id, vm.players[i].code_size);
			if (!create_process(i, j * step - k))
				return (0);
			++j;
		}
	}
	return (1);
}
