/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:26 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 19:12:16 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

int init_players_struct(t_player *players)
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

int 	init_corewar()
{
	vm.rounds_all = 0;
	vm.processes = NULL;
	vm.last_alive = NULL;
	vm.cycles_all = 0;
	vm.cycle_current = 0;
	vm.cycles_to_die = CYCLE_TO_DIE;
	vm.players_sum = 0;
	ft_bzero(vm.players, (sizeof(t_player)) * (MAX_PLAYERS + 1));
	ft_bzero(vm.arena, MEM_SIZE);
	init_players_struct(NULL);
	return (1);
}

int 	main(int argc, char **argv)
{
	if (argc <= 1)
		return (print_usage(0, 1));
	else
		if (!init_corewar() || !check_args(argc, argv))
			return (0);
	if (!create_players(argv))
	{
		ft_printf("error with player's file");
		return (0);
	}
	ft_printf("set %d - player was - %d\n", vm.players_temp[0].id, 0);
	ft_printf("set %d - player was - %d\n", vm.players_temp[1].id, 1);
	ft_printf("set %d - player was - %d\n", vm.players_temp[2].id, 2);
	ft_printf("set %d - player was - %d\n", vm.players_temp[3].id, 3);
	ft_printf("set %d - player was - %d\n", vm.players_temp[4].id, 4);
	printf("ok");
	if (!init_game())
		return (0);
	print_process();
	print_arena();
	return (0);
}