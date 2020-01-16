/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:26 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/15 19:24:39 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

int 	init_players_struct()
{
	int i;

	i = -1;
	while (++i <= MAX_PLAYERS)
	{
		vm.players[i].id = 0;
		vm.players[i].name = NULL;
		vm.players[i].comment = NULL;
		vm.players[i].code = NULL;
		vm.players[i].code_size = 0;
		vm.players[i].is_alive = 0;
		vm.players[i].lives_all = 0;
		vm.players[i].lives_last = 0;
		vm.players[i].lives_current = 0;
	}
	return (1);
}

//int 	init_proc_struct()
//{
//
//}

int 	init_corewar()
{
	vm.rounds_all = 0;
	vm.processes = NULL;
	vm.last_alive = NULL;
	vm.cycles_all = 0;
	vm.cycle_current = 0;
	vm.cycles_to_die = CYCLE_TO_DIE;
	vm.players_sum = 0;
	init_players_struct();
}

int 	main(int argc, char **argv)
{
	if (argc <= 1)
		return (print_usage(0, 1));
	else
	{
		if (!init_corewar())
			return (0);
		check_args(argc, argv);
	}
	ft_printf("%d %s %d\n", vm.players[0].id, "- player was", 0);
	ft_printf("%d %s %d\n", vm.players[1].id, "- player was", 1);
	ft_printf("%d %s %d\n", vm.players[2].id, "- player was", 2);
	ft_printf("%d %s %d\n", vm.players[3].id, "- player was", 3);
	return (0);
}