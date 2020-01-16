/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:47:07 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/16 17:47:08 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

int		is_set(int number, int max)
{
	int i;

	i = -1;
	while (++i < max)
		if (vm.players[i].id == number)
			return (1);
	return (0);
}

void	set_id(int player_k)
{
	int i;

	i = 1;
	while (is_set(i, vm.players_sum))
		++i;
	vm.players[player_k].id = i;
}

int		load_player(char *player_filename, int player_k)
{
	if (vm.players[player_k].id == 0)
		set_id(player_k);
	return (1);
}

int		create_players(int argc, char **argv)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (argv[++i])
	{
		if (ft_strstr(argv[i], ".cor"))
			if (!load_player(argv[i], k))
				return (0);
	}
	return (1);
}