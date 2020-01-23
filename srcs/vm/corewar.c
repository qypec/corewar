/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:26 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/23 18:49:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		init_players_struct(t_player *players)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		vm.players_temp[i].id = 0;
		vm.players_temp[i].name[PROG_NAME_LENGTH] = '\0';
		vm.players_temp[i].comment[COMMENT_LENGTH] = '\0';
		vm.players_temp[i].code_size = 0;
		vm.players_temp[i].is_alive = 0;
		vm.players_temp[i].lives_all = 0;
		vm.players_temp[i].lives_last = 0;
		vm.players_temp[i].lives_current = 0;
	}
	return (1);
}

int		init_corewar(void)
{
	vm.process_count = 0;
	vm.processes = NULL;
	vm.last_alive = NULL;
	vm.cycles_all = 0;
	vm.cycle_current = 0;
	vm.cycles_to_die = CYCLE_TO_DIE;
	vm.cycles_to_die_last = CYCLE_TO_DIE;
	vm.players_sum = 0;
	vm.dump_cycle = 0;
	vm.checks = 0;
	ft_bzero(vm.arena, MEM_SIZE);
	ft_bzero(vm.arena_id, MEM_SIZE * sizeof(int));
	init_players_struct(NULL);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
		return (print_usage(0, 1));
	if (!init_corewar() || !check_args(argc, argv))
		return (0);
	if (!create_players(argv))
	{
		ft_printf("error with player's file");
		return (0);
	}
	printf("ok");
	if (!init_game())
		return (0);
	if (DEBUG)
		print_process();
	battle();
	return (0);
}
